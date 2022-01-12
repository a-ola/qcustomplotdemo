#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include <qcustomplot.h>
#include <QtCore/QVariant>
#include <QApplication>
#include <QFrame>
#include <QLabel>
#include <QMainWindow>
#include <QMenuBar>
#include <QStatusBar>
#include <QVBoxLayout>
#include <QWidget>
#include <string>
#include <iostream>
#include <regex>




class MainWindow : public QMainWindow
{
	Q_OBJECT
  
public:
	explicit MainWindow(QWidget *parent = 0);

  	void timerEvent( QTimerEvent * );
	void addRealtimeSample(double v);

private slots:
	void titleDoubleClick(QMouseEvent *event);
	void axisLabelDoubleClick(QCPAxis* axis, QCPAxis::SelectablePart part);
	void legendDoubleClick(QCPLegend* legend, QCPAbstractLegendItem* item);
	void selectionChanged();
	void mousePress();
	void mouseWheel();
	void addRandomGraph();
	void addRealtimeGraph();
	void addCPUtempGraph();
	void removeSelectedGraph();
	void removeAllGraphs();
	void contextMenuRequest(QPoint pos);
	void moveLegend();
	void graphClicked(QCPAbstractPlottable *plottable, int dataIndex);
  
private:
	QWidget *centralWidget;
	QVBoxLayout *verticalLayout;
	QFrame *frame_2;
	QVBoxLayout *verticalLayout_3;
	QCustomPlot *customPlot;
	QFrame *frame;
	QVBoxLayout *verticalLayout_2;
	QLabel *label;
	QMenuBar *menuBar;
	QStatusBar *statusBar;
	QSharedPointer<QCPDataContainer<QCPGraphData> > animdata;
	const int nRealtimePoints = 500;
	const double dt = 0.02;
	double t = 0;
};

#endif // MAINWINDOW_H
