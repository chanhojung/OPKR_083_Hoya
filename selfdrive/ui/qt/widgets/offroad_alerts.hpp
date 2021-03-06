#pragma once

#include <QFrame>
#include <QStackedWidget>
#include <QPushButton>
#include <QStringList>

struct Alert {
  QString text;
  int severity;
};

class OffroadAlert : public QFrame {
  Q_OBJECT

public:
  explicit OffroadAlert(QWidget *parent = 0);
  QVector<Alert> alerts;
  QStringList alert_keys;
  bool updateAvailable;

private:
  QStackedWidget *alerts_stack;
  QPushButton *reboot_btn;
  void parse_alerts();

signals:
  void closeAlerts();

public slots:
  void refresh();
};