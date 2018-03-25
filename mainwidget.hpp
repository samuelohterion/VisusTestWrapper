#ifndef MAINWIDGET_HPP
#define MAINWIDGET_HPP

#include <QWidget>
#include <QProcess>
#include <QClipboard>

namespace Ui {
	class MainWidget;
}

class MainWidget : public QWidget
{
		Q_OBJECT

	public:
		explicit MainWidget(QWidget *parent = 0);
		~MainWidget();
    QClipboard
    *cb;

	private:
		Ui::MainWidget *ui;

	public slots:

		void slotNewExamination( );
        void slotScanSIC( );
        void slotFinishExamination( );
        void slotStartFrACT( );
};

#endif // MAINWIDGET_HPP
