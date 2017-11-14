#ifndef CALCULATOR1_H
#define CALCULATOR1_H

#include <QtWidgets/QMainWindow>
#include "ui_calculator1.h"

class Calculator1 : public QMainWindow
{
	Q_OBJECT

public:
	Calculator1(QWidget *parent = 0);
	~Calculator1();
	QString temp;    
	QString temp1; 
	void keyPressEvent(QKeyEvent *); 
	
public  slots:
	void button_1_click();
	void button_2_click();
	void button_3_click();
	void button_4_click();
	void button_5_click();
	void button_6_click();
	void button_7_click();
	void button_8_click();
	void button_9_click();
	void button_0_click();

	void button_add_click();
	void button_sub_click();
	void button_mul_click();
	void button_divide_click();
	void button_is_click();

	void button_cls_click();
	void button_left_click();
	void button_right_click();
	void button_back_click();
	
	

private:
	Ui::Calculator1Class ui;
};

#endif // CALCULATOR1_H
