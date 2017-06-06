#include "gui.h"
#include "ui_gui.h"

Gui::Gui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Gui)
{
    ui->setupUi(this);
    SetTempChart();
}

Gui::~Gui()
{
    delete ui;
}

void Gui::SetTempChart()
{

    chart->legend()->hide();
    chart->addSeries(tempSeries);
    chart->createDefaultAxes();
    chart->axisX()->setRange(0,10);
    chart->axisX()->hide();
    chart->axisY()->setRange(-20,50);
    chart->setTitle("Temperatur (°C)");
    chart->setAnimationOptions(QChart::AllAnimations);
    chartView->setRenderHint(QPainter::Antialiasing);
    setCentralWidget(chartView);
    resize(400, 300);

}

void Gui::SetLightChart()
{

    chart->legend()->hide();
    chart->addSeries(lightSeries);
    chart->createDefaultAxes();
    chart->axisX()->setRange(0,10);
    chart->axisX()->hide();
    chart->axisY()->setRange(0,1000);
    chart->setTitle("Light intensity (Lux)");
    chart->setAnimationOptions(QChart::AllAnimations);
    chartView->setRenderHint(QPainter::Antialiasing);
    setCentralWidget(chartView);
    resize(400, 300);
}

void Gui::AddTemp(int data){

    tempSeries->append(tempCount,data);
    if(tempCount>10){
        chart->axisX()->setRange(tempCount-10,tempCount);
    }

}

void Gui::DataInput(int id, int data){

    if(id == 1){
        tempCount++;
        AddTemp(data);
    }

    if(id == 2){
        lightCount++;
        AddLight(data);
    }
}

void Gui::AddLight(int data){
    lightSeries->append(lightCount,data);
    if(lightCount>10){
        chart->axisX()->setRange(lightCount-10,lightCount);
    }
}

void Gui::on_actionTempuratur_triggered()
{
    tempCount=0;
    SetLightChart();
}

void Gui::on_actionLight_triggered()
{
    lightCount=0;
    SetTempChart();
}
