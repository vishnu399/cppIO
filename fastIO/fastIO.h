//
// Created by Vishnu on 6/26/2020.
//

#ifndef CPPIO_FASTIO_H
#define CPPIO_FASTIO_H
namespace fastIO{
    #define _I __attribute__((always_inline))inline
    #define _rt return*this;
    #define _f __X&operator,
    #define _F _X&operator,
    #define _f1 if(kk){char _t=P();for(;kk&&dd[_t];_t=P());if(_t)for(;_t&&!dd[_t];_t=P())
    static char inp[1024],*sde=inp+1024;static const char*sp=sde;struct __X{bool d[256],dd[256],kk=1,s=1;__X(){for(int i=48;i<58;d[i++]=1);d[45]=dd[32]=dd[10]=dd[13]=dd[9]=1;}
    _I void __ra(){size_t r=sde-sp;if(r<24){memcpy(inp,sp,r);size_t sz=fread(inp+r,1,1024-r,stdin);sp=inp;sde=inp+r+sz;if(sde!=inp+1024)*sde=0;}if(sp==sde)kk=0;}_I char P()
    {if(!(sde-sp))__ra();return*(sp++);}_I _f(char&x){if(kk)for(x=P();kk&&dd[x];x=P());_rt}_I _f(char*x){_f1 *x++=_t;*x=0;}_rt}_I _f(std::string&x){x="";_f1 x+=_t;}_rt}
    template<class T>_I _f(T&x){if(kk){x=s=0;__ra();while(!d[*sp])__ra(),++sp;if(*sp=='-')s=1;else x=(*sp&15);++sp;while(d[*sp])x=(x<<1)+(x<<3)+(*(sp++)&15);if(s)x=-x;}_rt}}in;
    static char _ot[1024],*sdE=_ot+1024,*sP=_ot;struct _X{unsigned _o[10000];_X(){for(int i=0;i<10000;i++){unsigned v=i;char*o=(char*)(_o + i);o[3]=v%10+'0';o[2]=(v%100)/10+'0';
    o[1]=v%1000/100+'0';o[0]=v%10000/1000;if(o[0])o[0]|=0x30;else if(o[1]!='0')o[0]|=0x20;else if(o[2]!='0')o[0]|=0x10;}}_I void wa(){if(sdE-sP<24)
    {w();sP=_ot;sdE=_ot+sizeof(_ot);}}_I _F(char x){*(sP++)=x;_rt}template<class T>_I _F(T x){wa();unsigned g[3],*b=g+2;g[0]=x<0?-x:x;g[2]=_o[g[0]%10000];
    g[0]=1ll*g[0]*3518437209>>45;if(g[0]){g[1]=_o[g[0]%10000];g[0]=1ll*g[0]*3518437209>>45;g[2]|=0x30303030;b--;}if(g[0]){g[0]=_o[g[0]];g[1]|=0x30303030;b--;}
    char*f=(char*)b;f+=3-(*f>>4);char*str=(char*)g;if(x<0)*--f='-';memcpy(sP,f,(str+12)-f);sP+=(str+12)-f;_rt}_I void w(){fwrite(_ot,1,sizeof(_ot)-(sdE-sP),stdout);}~_X(){w();}}out;
}
#endif //CPPIO_FASTIO_H
