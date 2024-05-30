//
// Created by Lenovo on 24-5-24.
//

#ifndef SIMS_ADMINFORM_H
#define SIMS_ADMINFORM_H

#include <QWidget>

namespace SystemUi {
    QT_BEGIN_NAMESPACE
    namespace Ui { class AdminForm; }
    QT_END_NAMESPACE

    class AdminForm : public QWidget {
    Q_OBJECT

    public:
        explicit AdminForm(QWidget *parent = nullptr);

        ~AdminForm() override;

    private:
        Ui::AdminForm *ui;
    };
}

#endif //SIMS_ADMINFORM_H
