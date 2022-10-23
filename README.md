# Integral Calculator
 
 ## Build
 
 Open project directory and:
 
 ```
 $ mkdir build
 $ cd build
 $ cmake ..
 $ make
 $ cd ..
 ```
 
 ## Usage
 
 If you want to calculate
 
https://latex.codecogs.com/svg.image?\int_{a}^{b}F(x)dx&space;\\&space;\\(a\in&space;\mathbb{R},&space;\,b&space;\in&space;\mathbb{R}\cup&space;\{&plus;\infty\})
 
 run
 
 ```
 ./calculate.sh a b eps "F(x)"
 ```
 
 where eps is desired accuracy. You can skip this argument. The default value is 1e-14.
 
 Write F(x) as if you were writing it in:
 ```
 #include <cmath>
 using namespace std
 ...
 ```
 Quotes ("F(x)") are optional, use them if you use spaces in F(x).
 
 ## About maths
 
 I use [composite Simpson's rule](https://en.wikipedia.org/wiki/Simpson%27s_rule#Composite_Simpson's_rule) for calculation.
 Let's assume 
 
 <img src="https://latex.codecogs.com/svg.image?S_n&space;=&space;(2/3)h(f(a)/2&space;&plus;&space;2\sum_{j=1}^{n}f(a&plus;(2j-1)h)&space;&plus;&space;\sum_{j=1}^{n-1}f(a&plus;2jh)&space;&plus;&space;f(b)/2)&space;">
 <img src="https://latex.codecogs.com/svg.image?h&space;=&space;(b-a)/2n&space;">
 
 If integral can be solved, then:
 
 <img src="https://latex.codecogs.com/svg.image?\lim_{n\to&space;&plus;\infty&space;}{S_n}&space;=&space;\int_{a}^{b}f(x)dx&space;">
 
 Due to Cauchy's criteria:
 
 <img src="https://latex.codecogs.com/svg.image?\exists&space;\lim_{n\to&space;&plus;\infty&space;}{S_n}&space;\Leftrightarrow&space;\forall&space;\varepsilon&space;\,\exists&space;N\,&space;&space;\forall&space;n,&space;m&space;>&space;N&space;\,\,&space;|S_n-S_m|<\varepsilon">
 
Program creates a sequence: <img src="https://latex.codecogs.com/svg.image?S_{10},&space;S_{20},&space;...,&space;S_n,&space;S_{2n}&space;">  and returns <img src="https://latex.codecogs.com/svg.image?S_{2n}&space;">  as soon as <img src="https://latex.codecogs.com/svg.image?|S_{2n}-S_n|&space;<&space;eps&space;">  (eps is one of command line arguments).
If <img src="https://latex.codecogs.com/svg.image?n>10^7&space;">, program says that metod is not applicable.
 
 
