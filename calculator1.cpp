
#include "calculator1.h"
#include "qevent.h"
#include "QDebug"
double result=0;
Calculator1::Calculator1(QWidget *parent)  
	: QMainWindow(parent)
{
	ui.setupUi(this);
	    
	connect(ui.num1, SIGNAL(clicked()), this, SLOT(button_1_click()));
	connect(ui.num2, SIGNAL(clicked()), this, SLOT(button_2_click()));
	connect(ui.num3, SIGNAL(clicked()), this, SLOT(button_3_click()));
	connect(ui.num4, SIGNAL(clicked()), this, SLOT(button_4_click()));
	connect(ui.num5, SIGNAL(clicked()), this, SLOT(button_5_click()));
	connect(ui.num6, SIGNAL(clicked()), this, SLOT(button_6_click()));
	connect(ui.num7, SIGNAL(clicked()), this, SLOT(button_7_click()));
	connect(ui.num8, SIGNAL(clicked()), this, SLOT(button_8_click()));
	connect(ui.num9, SIGNAL(clicked()), this, SLOT(button_9_click()));
	connect(ui.num0, SIGNAL(clicked()), this, SLOT(button_0_click()));

	connect(ui.add, SIGNAL(clicked()), this, SLOT(button_add_click()));
	connect(ui.sub, SIGNAL(clicked()), this, SLOT(button_sub_click()));
	connect(ui.mul, SIGNAL(clicked()), this, SLOT(button_mul_click()));
	connect(ui.divide, SIGNAL(clicked()), this, SLOT(button_divide_click()));
	connect(ui.equal, SIGNAL(clicked()), this, SLOT(button_is_click()));
	connect(ui.left, SIGNAL(clicked()), this, SLOT(button_left_click()));
	connect(ui.right, SIGNAL(clicked()), this, SLOT(button_right_click()));

	connect(ui.clear0, SIGNAL(clicked()), this, SLOT(button_cls_click()));
	
	connect(ui.back, SIGNAL(clicked()), this, SLOT(button_back_click()));
	

	
	
}


Calculator1::~Calculator1()
{

}
void Calculator1::button_1_click()
{
	temp += "1";
	ui.lineEdit_operation->setText(temp);
}
void Calculator1::button_2_click()
{
	temp += "2";
	ui.lineEdit_operation->setText(temp);
}
void Calculator1::button_3_click()
{
	temp += "3";
	ui.lineEdit_operation->setText(temp);
}
void Calculator1::button_4_click()
{
	temp += "4";
	ui.lineEdit_operation->setText(temp);
}
void Calculator1::button_5_click()
{
	temp += "5";
	ui.lineEdit_operation->setText(temp);
}
void Calculator1::button_6_click()
{
	temp += "6";
	ui.lineEdit_operation->setText(temp);
}
void Calculator1::button_7_click()
{
	temp += "7";
	ui.lineEdit_operation->setText(temp);
}
void Calculator1::button_8_click()
{
	temp += "8";
	ui.lineEdit_operation->setText(temp);
}
void Calculator1::button_9_click()
{
	temp += "9";
	ui.lineEdit_operation->setText(temp);
}
void Calculator1::button_0_click()
{
	temp += "0";
	ui.lineEdit_operation->setText(temp);
}

void Calculator1::button_sub_click()
{
	temp += "-";
	ui.lineEdit_operation->setText(temp);
}
void Calculator1::button_add_click()
{
	temp += "+";
	ui.lineEdit_operation->setText(temp);
}
void Calculator1::button_mul_click()
{
	temp += "*";
	ui.lineEdit_operation->setText(temp);
}
void Calculator1::button_divide_click()
{
	temp += "/";
	ui.lineEdit_operation->setText(temp);
}
void Calculator1::button_left_click()
{
	temp += "(";
	ui.lineEdit_operation->setText(temp);
}
void Calculator1::button_right_click()
{
	temp += ")";
	ui.lineEdit_operation->setText(temp);
}
void Calculator1::button_back_click()
{
	temp.chop(1);                           
	ui.lineEdit_operation->setText(temp);
}
void Calculator1::button_cls_click()
{
	temp = "";
	result = 0;		
	ui.lineEdit_operation->setText(temp);
	ui.lineEdit_result->setText("");
}
void Calculator1::button_is_click()
{
	char* p;
	QByteArray ba = temp.toLatin1(); //QString 转化成 char*
	p = ba.data();                   //p 指向表达式字符串
	int i,j,k;                       //存放数字个数、操作符个数，优先级个数
	double c;                        //存放临时数据
	int pri[100];                     //存放优先级
	i=0;j=0;k=0;                     //初始化
	char n[100];					//存放操作符号
	double  m[100];					//存放数字
	char  tmpchar;					//存放临时字符
	bool  first=true;               //是否为第一个数字
	for (int iii = 0; iii < 100; iii++)  //数据初始化
		m[iii] = 0.0;
	for (int iii = 0; iii < 100; iii++)  //数据初始化
		pri[iii] = 0;
	for (int iii = 0; iii < 100; iii++)  //数据初始化
		n[iii] = 0;

	while(*p!=NULL)                     //表达式字符串遍历过程
	{
		tmpchar = *p;                   //得到当前字符
		
		if((tmpchar >='0')&&(tmpchar <='9'))  //判断当前字符是否为数字字符
		{	
			if (first)                        //如果为第一个数据，则数字个数增加一个
			{				
			m[i] = (double)(tmpchar - '0');	 //数字字符转化成数字并保存
			i++;                             //数字字符增加一个
			first = false;                   //定义数字个数不再是第一个
			}				
			else
			{
				m[i-1] = m[i-1]*10.+ (double)(tmpchar - '0');//实现大于10的数字操作					 
			}			
			p = p + 1;                          //指针指向下一个字符
		}
		else if ((tmpchar == '-') || (tmpchar == '+'))//判断当前字符是否为加减字符
		{
			first = true;					//定义数字个数是第一个
			pri[k] = 1;                     //定义优先级

			if (k == 0)         //必须首先判断，否则pri[k - 1]无法得到，因为k-1小于0了，程序会出错
			{
				n[j] = tmpchar;  //获得操作字符
				p = p + 1;//指针指向下一个字符
				j++;     //操作符字符增加一个
				k++;     //操作字符优先级增加一个
			}
			else       //不是第一个操作符，需要运行的程序
			{
				if (pri[k] > pri[k - 1])
				{
					n[j] = tmpchar; //获取操作符
					p = p + 1;//指针指向下一个字符
					j++;      //操作符字符增加一个
					k++;      //操作字符优先级增加一个

				}				
				else
				{
					if (n[j - 1] == '+')  //执行加操作
						c = m[i - 2] + m[i - 1];
					if (n[j - 1] == '-')//执行减操作
						c = m[i - 2] - m[i - 1];
					if (n[j - 1] == '*') //执行乘操作
						c = m[i - 1] * m[i - 2];
					if (n[j - 1] == '/') //执行除操作，m[i - 1]不能为零，否则出错
					{
						if (m[i - 1] == 0)
						{
							qDebug() << "除数不能为0 error !!!" << endl;
							return;
						}
						else
						c = (double)((m[i - 2]) / m[i - 1]);
					}
						
					m[i - 2] = c;
					i--; //数字个数减一
					j--; //操作字符个数减一
					k--; //操作字符优先级个数减一
				}
				//k++;
			}
		}
		else if((tmpchar =='*')||(tmpchar =='/'))
		{
			first = true; //定义数字个数是第一个
			pri[k]=2;        //定义优先级

			if (k == 0)//必须首先判断，否则pri[k - 1]无法得到，因为k-1小于0了，程序会出错
			{
				n[j] = tmpchar;
				p = p + 1;//指针指向下一个字符
				j++;  //操作字符加一
				k++;  //操作字符优先级加一
			}
			else //不是第一个操作符，需要运行的程序
			{
				if (pri[k] > pri[k - 1])
				{
					n[j] = tmpchar;
					p = p + 1;//指针指向下一个字符
					j++;  //操作字符加一
					k++;  //操作字符优先级加一

				}
				else
				{
					if (n[j - 1] == '+')
						c = m[i - 2] + m[i - 1];
					if (n[j - 1] == '-')
						c = m[i - 2] - m[i - 1];
					if (n[j - 1] == '*')
						c = m[i - 1] * m[i - 2];
					if (n[j - 1] == '/') //执行除操作，m[i - 1]不能为零，否则出错
					{
						if (m[i - 1] == 0)
						{
							qDebug() << "除数不能为0 error !!!" << endl;
							return;
						}
						else
						c = (double)((m[i - 2]) / m[i - 1]);
					}
					m[i - 2] = c;
					i--; //数字个数减一
					j--; //操作字符个数减一
					k--; //操作字符优先级个数减一
				}
				//k++;
			}
		}
		else if(tmpchar =='(')
		{
			first = true; //定义数字个数是第一个
			pri[k]=0;        //定义优先级为0，保证括号内的操作字符优先级高于”（“

			n[j] = tmpchar;  //获取操作字符，如果是”（“，必须增加字符，不需要判断优先级
			p = p + 1;//指针指向下一个字符
			j++;      //操作字符个数加一
			k++;      //操作字符优先级个数加一

		}
		else if (tmpchar ==')')
		{
			first = true; //定义数字个数是第一个
			p = p + 1;//指针指向下一个字符
			if (k == 0)  //保证表达式第一个字符不为”）“
			{
				qDebug()<<"input error !!!"<<endl;
				return;
			}
			else   //如果操作字符为”）“，不需要将其存入数组n[],直接计算（）内的数据即可
			{

					if (n[j - 1] == '+')
						c = m[i - 2] + m[i - 1];
					if (n[j - 1] == '-')
						c = m[i - 2] - m[i - 1];
					if (n[j - 1] == '*')
						c = m[i - 1] * m[i - 2];
					if (n[j - 1] == '/') //执行除操作，m[i - 1]不能为零，否则出错
					{
						if (m[i - 1] == 0)
						{
							qDebug() << "除数不能为0 error !!!" << endl;
							return;
						}
						else
							c = (double)((m[i - 2]) / m[i - 1]);
					}
					m[i - 2] = c;
					i--; //数字个数减一，为了删掉一个数字
					j--; //操作字符个数减一，为了删掉一个操作符”+ - * /“
					k--; //操作字符优先级个数减一
			}
			j--;//操作字符个数减一，为了删掉”（“
			k--;//操作字符优先级个数减一，为了删掉”（“

		}
		
	}
	while (i != 1)  //循环计算得到输出结果
	{
		if (n[j - 1] == '+')
			c = m[i - 2] + m[i - 1];
		if (n[j - 1] == '-')
			c = m[i - 2] - m[i - 1];
		if (n[j - 1] == '*')
			c = m[i - 1] * m[i - 2];
		if (n[j - 1] == '/') //执行除操作，m[i - 1]不能为零，否则出错
		{
			if (m[i - 1] == 0)
			{
				qDebug() << "除数不能为0 error !!!" << endl;
				return;
			}
			else
				c = (double)((m[i - 2]) / m[i - 1]);
		}
		m[i - 2] = c;
		i--; //数字个数减一，为了删掉一个数字
		j--; //操作字符个数减一，为了删掉一个操作符”+ - * /“
	}   
	//m[0]就是结果
	result = m[0];	
	ui.lineEdit_operation->setText(temp+"=");
	temp1 = QString::number(result); 
	ui.lineEdit_result->setText(temp1);
}
void Calculator1::keyPressEvent(QKeyEvent *k)
{
	//int b = k->key();
	switch (k->key())
	{
	case Qt::Key_0:button_0_click(); break;
	case Qt::Key_1:button_1_click(); break;
	case Qt::Key_2:button_2_click(); break;
	case Qt::Key_3:button_3_click(); break;
	case Qt::Key_4:button_4_click(); break;
	case Qt::Key_5:button_5_click(); break;
	case Qt::Key_6:button_6_click(); break;
	case Qt::Key_7:button_7_click(); break;
	case Qt::Key_8:button_8_click(); break;
	case Qt::Key_9:button_9_click(); break;
	case Qt::Key_Plus:button_add_click(); break;         // +
	case Qt::Key_Minus:button_sub_click(); break;        // -
	case Qt::Key_Asterisk:button_mul_click(); break;     // *
	case Qt::Key_Slash:button_divide_click(); break;     // /
	case Qt::Key_Backspace:button_back_click(); break;   // ��
	case Qt::Key_Enter:button_is_click(); break;         // =
	
	
	default:break;
	}
}

