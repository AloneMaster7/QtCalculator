#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

enum Operation {Add=0,Subtract,Multiply,Divide,Reminder,_1_x,NullOp};

class Widget : public QWidget
{
    Q_OBJECT
    QLabel* lbl;
    QLabel* history;
    double firstOp,secondOp;
    bool waitFor,justDisplay;
    Operation op;
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    void resizeEvent(QResizeEvent *event) override;
};
#endif // WIDGET_H
