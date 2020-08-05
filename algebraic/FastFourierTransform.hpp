#include "../other/template.hpp"
#include "MyComplex.hpp"
class FastFourierTransform {
private:
    static void dft(std::vector<MyComplex>& func, int inverse) {
        int sz = func.size();
        if (sz == 1)return;
        std::vector<MyComplex> veca, vecb;
        rep(i, sz / 2) {
            veca.push_back(func[2 * i]);
            vecb.push_back(func[2 * i + 1]);
        }
        dft(veca, inverse); dft(vecb, inverse);
        MyComplex now = 1, zeta = std::polar(1.0, inverse * 2.0 * acos(-1) / sz);
        rep(i, sz) {
            func[i] = veca[i % (sz / 2)] + now * vecb[i % (sz / 2)];
            now *= zeta;
        }
    }
public:
    template<typename T>
    static std::vector<double> multiply(const std::vector<T>& f, const std::vector<T>& g) {
        std::vector<MyComplex> nf, ng;
        int sz = 1;
        while (sz < f.size() + g.size())sz *= 2;
        nf.resize(sz); ng.resize(sz);
        rep(i, f.size()) {
            nf[i] = f[i];
            ng[i] = g[i];
        }
        dft(nf, 1);
        dft(ng, 1);
        rep(i, sz)nf[i] *= ng[i];
        dft(nf, -1);
        std::vector<double> res(sz);
        rep(i, sz)res[i]=nf[i].real() / sz;
        return res;
    }
};