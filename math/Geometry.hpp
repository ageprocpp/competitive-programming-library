#include "../other/template.hpp"
static bool equal(double lhs, double rhs) { return std::abs(lhs - rhs) < eps; }

class Point2D : public std::complex<double> {
	using C = std::complex<double>;

  public:
	Point2D() = default;
	Point2D(double x, double y) : C(x, y) {}
	Point2D(const std::complex<double>& c) : C(c) {}
	Point2D(std::complex<double>&& c) : C(c) {}

	double get_x() const { return real(); }
	double get_y() const { return imag(); }

	double abs() const { return std::abs(*this); }
	bool equals(const Point2D& x) {
		return equal(real(), x.real()) && equal(imag(), x.imag());
	}

	Point2D unit() const { return Point2D(*this / abs()); }
	Point2D normal() const { return *this * std::complex<double>(0, 1); }

	friend double dot(const Point2D& lhs, const Point2D& rhs);
	friend double cross(const Point2D& lhs, const Point2D& rhs);
	friend Point2D rotate(const Point2D& p, double theta);
};

double dot(const Point2D& lhs, const Point2D& rhs) {
	return lhs.real() * rhs.real() + lhs.imag() * rhs.imag();
}
double cross(const Point2D& lhs, const Point2D& rhs) {
	return lhs.real() * rhs.imag() - lhs.imag() * rhs.real();
}
Point2D rotate(const Point2D& p, double theta) {
	return Point2D(p * std::polar(1.0, theta));
}

class Line2D {
  protected:
	Point2D s, t;

  public:
	Line2D() = default;
	Line2D(const Point2D& s_, const Point2D& t_) : s(s_), t(t_) {}
	Line2D(double A, double B, double C) {
		if (equal(A, 0))
			s = Point2D(0, C / B), t = Point2D(1, C / B);
		else if (equal(B, 0))
			s = Point2D(C / A, 0), t = Point2D(C / A, 1);
		else
			s = Point2D(0, C / B), t = Point2D(C / A, 0);
	}

	friend Point2D projection(const Line2D& l, const Point2D& p);
	friend bool is_orthogonal(const Line2D& a, const Line2D& b);
	friend bool is_parallel(const Line2D& a, const Line2D& b);
	friend Point2D cross_point(const Line2D& a, const Line2D& b);
};

class Segment2D : public Line2D {
  public:
	Segment2D() = default;
	Segment2D(const Point2D& s, const Point2D& t) : Line2D(s, t) {}

	friend bool is_intersect(const Segment2D& a, const Segment2D& b);
	friend double distance(const Segment2D& l, const Point2D& p);
	friend double distance(const Segment2D& a, const Segment2D& b);
};

class Circle2D {
	Point2D p;
	double r;

  public:
	Circle2D() = default;
	Circle2D(const Point2D& p_, double r_) : p(p_), r(r_) {}
};

Point2D projection(const Line2D& l, const Point2D& p) {
	double t = dot(p - l.s, l.s - l.t) / std::norm(l.s - l.t);
	return l.s + (l.s - l.t) * t;
}

Point2D reflection(const Line2D& l, const Point2D& p) {
	return p + (projection(l, p) - p) * 2.0;
}

// 1: COUNTER_CLOCKWISE
// -1: CLOCKWISE
// 2: ONLine2D_BACK
// -2: ONLine2D_FRONT
// 0: ON_Segment2D
int counter_clockwise(const Point2D& a, Point2D b, Point2D c) {
	b -= a, c -= a;
	if (cross(b, c) > eps) return 1;
	if (cross(b, c) < -eps) return -1;
	if (dot(b, c) < 0) return 2;
	if (std::norm(b) < std::norm(c)) return -2;
	return 0;
}

bool is_orthogonal(const Line2D& a, const Line2D& b) {
	return equal(dot(a.t - a.s, b.t - b.s), 0);
}

bool is_parallel(const Line2D& a, const Line2D& b) {
	return equal(cross(a.t - a.s, b.t - b.s), 0);
}

bool is_intersect(const Segment2D& a, const Segment2D& b) {
	return counter_clockwise(a.s, a.t, b.s) *
				   counter_clockwise(a.s, a.t, b.t) <=
			   0 &&
		   counter_clockwise(b.s, b.t, a.s) *
				   counter_clockwise(b.s, b.t, a.t) <=
			   0;
}

Point2D cross_point(const Line2D& a, const Line2D& b) {
	double d1 = cross(a.t - a.s, b.t - b.s);
	double d2 = cross(a.t - a.s, a.t - b.s);
	if (equal(std::abs(d1), 0) && equal(std::abs(d2), 0)) return a.s;
	return b.s + (b.t - b.s) * (d2 / d1);
}

double distance(const Point2D& x, const Point2D& y) { return std::abs(x - y); }

double distance(const Segment2D& l, const Point2D& p) {
	if (dot(l.t - l.s, p - l.s) < eps) return std::abs(p - l.s);
	if (dot(l.s - l.t, p - l.t) < eps) return std::abs(p - l.t);
	return std::abs(cross(l.t - l.s, p - l.s) / (l.t - l.s));
}

double distance(const Segment2D& a, const Segment2D& b) {
	if (is_intersect(a, b)) return 0;
	double ans = distance(a, b.s);
	chmin(ans, distance(a, b.t));
	chmin(ans, distance(b, a.s));
	chmin(ans, distance(b, a.t));
	return ans;
}

double polygon_area(const std::vector<Point2D>& v) {
	double res = cross(v.back(), v[0]);
	rep(i, v.size() - 1) res += cross(v[i], v[i + 1]);
	return res * 0.5;
}

bool is_convex(const std::vector<Point2D>& v) {
	const int n = v.size();
	if (counter_clockwise(v[n - 1], v[0], v[1]) == -1) return false;
	if (counter_clockwise(v[n - 2], v[n - 1], v[0]) == -1) return false;
	rep(i, n - 2) {
		if (counter_clockwise(v[i], v[i + 1], v[i + 2]) == -1) return false;
	}
	return true;
}

int is_contained(const std::vector<Point2D>& v, const Point2D& p) {
	bool in = false;
	rep(i, v.size()) {
		Point2D a = v[i] - p, b = v[i == v.size() - 1 ? 0 : i + 1] - p;
		if (a.get_y() > b.get_y()) std::swap(a, b);
		if (a.get_y() < eps && eps < b.get_y() && cross(a, b) < -eps)
			in ^= true;
		if (cross(a, b) == 0 && dot(a, b) <= 0) return 1;
	}
	return in ? 2 : 0;
}

std::vector<Point2D> convex_hull(std::vector<Point2D> p) {
	int n = p.size(), k = 0;
	std::sort(all(p), [](const Point2D& a, const Point2D& b) {
		return a.get_x() != b.get_x() ? a.get_x() < b.get_x()
									  : a.get_y() < b.get_y();
	});
	std::vector<Point2D> res(2 * n);
	for (int i = 0; i < n; res[k++] = p[i++]) {
		while (k >= 2 &&
			   cross(res[k - 1] - res[k - 2], p[i] - res[k - 1]) < -eps)
			k--;
	}
	for (int i = n - 2, t = k + 1; i >= 0; res[k++] = p[i--]) {
		while (k >= t &&
			   cross(res[k - 1] - res[k - 2], p[i] - res[k - 1]) < -eps)
			k--;
	}
	res.resize(k - 1);
	return res;
}

double convex_polygon_diameter(const std::vector<Point2D>& p) {
	int cur = 0;
	double res = 0;
	rep(i, p.size()) {
		double cur_dist = distance(p[i], p[cur]), nxt_dist;
		while (true) {
			nxt_dist = distance(p[i], p[cur + 1 == p.size() ? 0 : cur + 1]);
			if (cur_dist > nxt_dist) break;
			cur_dist = nxt_dist;
			cur = cur + 1 == p.size() ? 0 : cur + 1;
		}
		chmax(res, cur_dist);
	}
	return res;
}

std::istream& operator>>(std::istream& ist, Point2D& p) {
	double x, y;
	ist >> x >> y;
	p = Point2D(x, y);
	return ist;
}

std::ostream& operator<<(std::ostream& ost, const Point2D& p) {
	ost << p.get_x() << ' ' << p.get_y();
	return ost;
}