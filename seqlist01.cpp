/*课后习题

	a.	完善存储整型数据的顺序表的类定义，完善基本的成员函数，并给出以下功能函数的具体实现。
		i.	从顺序表中删除具有最小值的元素并由函数返回被删元素的值，空出的位置由最后一个元素填补
			int deletemin();

		ii.	从顺序表中删除与给定x相等的所有元素
			void deleteSame(int x);

		iii.从顺序表中删除其值在给定 s与t之间（s < t）的所有元素,不包括s和t
			void deleteSome(int s, int t);
*/
#include <iostream>
using namespace std;
class  SeqArray  //顺序表
{
private:
    int* arr; //数组的起始地址
    int N;//数组规模
    int n;//数组当前元素个数
public:
    SeqArray(int NN=10);
    ~SeqArray();
    bool insertElement(int value);//向顺序表中插入value,如果成功返回true，否则返回false
    int deletemin();
    void deleteSame(int x);
    void deleteSome(int s, int t);
    void print(); //输出顺序表的数据
};
//请给出各个成员函数的具体实现
SeqArray::SeqArray(int NN)
{
    //todo-请给出具体实现代码
    if (NN <= 0) NN = 10;   //规模非法时取默认值
    N = NN;
    n = 0;                  //初始为空表
    arr = new int[N];
}
SeqArray::~SeqArray()
{
   //todo-请给出具体实现代码
    delete[] arr;           //释放动态数组
    arr = nullptr;
}
bool SeqArray::insertElement(int value)
{
    //todo-请给出具体实现代码
    if (n >= N) return false;   //表已满，插入失败
    arr[n] = value;             //新元素放在表尾
    n++;
    return true;
}
int SeqArray::deletemin()
{
  //todo-请给出具体实现代码
    if (n == 0) return 0;       //空表，无最小值
    int pos = 0;                //pos记录最小值所在下标
    for (int i = 1; i < n; i++)
        if (arr[i] < arr[pos]) pos = i;
    int minval = arr[pos];      //保存被删元素的值
    arr[pos] = arr[n - 1];      //用最后一个元素填补空出的位置
    n--;                        //表长减一
    return minval;
}
void  SeqArray::deleteSame(int x)
{
    //todo-请给出具体实现代码
    int k = 0;                  //k为保留下来的元素个数
    for (int i = 0; i < n; i++)
        if (arr[i] != x)        //不等于x则保留，就地前移
            arr[k++] = arr[i];
    n = k;
}
void  SeqArray::deleteSome(int s,int t)
{
    //todo-请给出具体实现代码
    if (s >= t) return;         //区间非法，不做处理
    int k = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] <= s || arr[i] >= t)   //s与t本身不删，只删中间的值
            arr[k++] = arr[i];
    n = k;
}
void SeqArray::print()
{
//todo-请给出具体实现代码
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

//请不要修改下面main函数中的代码
int main()
{
    // n 表示要输入的测试元素个数， minval记录删除后的最小值，
    //samevalue表示指定删除的数据，s和t表示要删除的数据的范围s<t
    int n,minval,samevalue, s, t, value;

    SeqArray a(20);
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin >> value;
        a.insertElement(value);
    }

    cout << "顺序表的数据为:";
    a.print();
    minval = a.deletemin();
    cout << "删除最小值后为:";
    a.print();
    cout << "最小值:" << minval << endl;
    cin >> samevalue;
    a.deleteSame(samevalue);
    cout << "删除相同值后为:";
    a.print();
    cin >> s >> t;
    a.deleteSome(s, t);
    cout << "删除指定范围的值后为:";
    a.print();
    return 0;
}
