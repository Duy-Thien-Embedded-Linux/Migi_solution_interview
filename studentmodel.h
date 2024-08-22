#ifndef STUDENTMODEL_H
#define STUDENTMODEL_H
#include <QAbstractListModel>

struct Student {
    QString id;
    QString name;
    QString dob;
    QString degree;
};

class StudentModel : public QAbstractListModel {
    Q_OBJECT

public:
    enum StudentRoles {
        IdRole = Qt::UserRole + 1,
        NameRole,
        DobRole,
        DegreeRole
    };

    StudentModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void addStudent(const QString &id, const QString &name, const QString &dob, const QString &degree);
    Q_INVOKABLE void deleteStudent(const QString &id);
    Q_INVOKABLE void deleteAll();

private:
    QList<Student> m_students;
};

#endif // STUDENTMODEL_H
