/*
	MIT License

	Copyright    (c) 2023 Julian Scheffers

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files    (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

void __adddf3(){}
void __addsf3(){}
void __addtf3(){}
void __divdf3(){}
void __divsf3(){}
void __divtf3(){}
void __eqdf2(){}
void __eqsf2(){}
void __eqtf2(){}
void __extenddftf2(){}
void __extendsfdf2(){}
void __extendsftf2(){}
void __fixdfdi(){}
void __fixdfsi(){}
void __fixsfdi(){}
void __fixsfsi(){}
void __fixtfdi(){}
void __fixtfsi(){}
void __fixunsdfdi(){}
void __fixunsdfsi(){}
void __fixunssfdi(){}
void __fixunssfsi(){}
void __fixunstfdi(){}
void __fixunstfsi(){}
void __floatdidf(){}
void __floatdisf(){}
void __floatditf(){}
void __floatsidf(){}
void __floatsisf(){}
void __floatsitf(){}
void __floatundidf(){}
void __floatundisf(){}
void __floatunditf(){}
void __floatunsidf(){}
void __floatunsisf(){}
void __floatunsitf(){}
void __gedf2(){}
void __gesf2(){}
void __getf2(){}
void __ledf2(){}
void __lesf2(){}
void __letf2(){}
void __muldf3(){}
void __mulsf3(){}
void __multf3(){}
void __negdf2(){}
void __negsf2(){}
void __negtf2(){}
void __subdf3(){}
void __subsf3(){}
void __subtf3(){}
void __truncdfsf2(){}
void __trunctfdf2(){}
void __trunctfsf2(){}
void __unorddf2(){}
void __unordsf2(){}
void __unordtf2(){}

void __ltsf2() __attribute__((alias("__lesf2")));
void __ltdf2() __attribute__((alias("__ledf2")));
void __lttf2() __attribute__((alias("__letf2")));
void __gtsf2() __attribute__((alias("__gesf2")));
void __netf2() __attribute__((alias("__eqtf2")));
void __nedf2() __attribute__((alias("__eqdf2")));
void __nesf2() __attribute__((alias("__eqsf2")));
void __gttf2() __attribute__((alias("__getf2")));
void __gtdf2() __attribute__((alias("__gedf2")));
