#include "mainwidget.hpp"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::MainWidget)
{
	ui->setupUi(this);

	QObject::connect( ui->pushButtonNewExamination, SIGNAL(	released( ) ), this, SLOT(slotNewExamination( ) ) );
    QObject::connect( ui->lineEditSICVal, SIGNAL( textChanged( QString ) ), this, SLOT( slotScanSIC( ) ) );
    QObject::connect( ui->pushButtonFinishExamination, SIGNAL( released( ) ), this, SLOT( slotFinishExamination( ) ) );
}

MainWidget::~MainWidget()
{
	delete ui;
}

void MainWidget::slotNewExamination( )
{
	ui->lineEditSICVal->setText( "----------" );
	ui->toolBox->setCurrentIndex( 1 );
	ui->toolBox->setItemText( 0, "Running Examination" );
    ui->lineEditSICVal->setFocus();
    ui->lineEditSICVal->setText( "" );
}

void MainWidget::slotScanSIC()
{
    QString scannedSIC = ui->lineEditSICVal->text( );
    QRegularExpression re( "LI\\d{8}", QRegularExpression::CaseInsensitiveOption );
    QRegularExpressionMatch m = re.match( scannedSIC );

    if( m.hasMatch( ) ) {

        ui->toolBox->setCurrentIndex( 2 );
        ui->toolBox->setItemText( 1, m.captured( 0 ) );
    }
}
void MainWidget::slotFinishExamination( )
{
    ui->toolBox->setCurrentIndex( 3 );
}
