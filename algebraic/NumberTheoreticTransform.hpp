#pragma once
#include "../other/template.hpp"
#include "ModInt.hpp"
//167772161,3
//469762049,3
//924844033,5
//998244353,3
//1012924417,5
//1224736769,3
const unsigned int ModInt::modulo=998244353;
class NumberTheoreticTransform{
	private:
    static void ntt(std::vector<ModInt>& func, const bool& inverse) {
        int sz = func.size();
        if (sz == 1)return;
        std::vector<ModInt> veca, vecb;
        rep(i, sz / 2) {
            veca.push_back(func[2 * i]);
            vecb.push_back(func[2 * i + 1]);
        }
        ntt(veca, inverse); ntt(vecb, inverse);
        ModInt now = 1, zeta;
		if(inverse)zeta=mypow(ModInt(3),ModInt::modulo-1-(ModInt::modulo-1)/sz);
		else zeta=mypow(ModInt(3),(ModInt::modulo-1)/sz);
        rep(i, sz) {
            func[i] = veca[i % (sz / 2)] + now * vecb[i % (sz / 2)];
            now *= zeta;
        }
    }
public:
    template<typename T>
    static std::vector<ModInt> multiply(const std::vector<T>& f, const std::vector<T>& g) {
        std::vector<ModInt> nf, ng;
        int sz = 1;
        while (sz < f.size() + g.size())sz *= 2;
        nf.resize(sz); ng.resize(sz);
        rep(i, f.size()) {
            nf[i] = f[i];
            ng[i] = g[i];
        }
        ntt(nf, false);
        ntt(ng, false);
        rep(i, sz)nf[i] *= ng[i];
        ntt(nf, true);
		rep(i,sz)nf[i]/=sz;
        return nf;
    }
};