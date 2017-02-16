// The first Qt Program
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
	// 创建 QApplication 实例
	QApplication hello(argc, argv);
	// 添加一个文本组件
	QLabel *label = new QLabel;
	label->setText("Hello, Qt");
	label->show();

	// 进入事件循环
	return hello.exec();
}
