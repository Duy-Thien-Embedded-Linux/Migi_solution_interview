#include "studentmodel.h"
#include <QDebug>

StudentModel::StudentModel(QObject *parent)
    : QAbstractListModel(parent) {}

int StudentModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_students.count();
}

QVariant StudentModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() >= m_students.size())
        return QVariant();

    const Student &student = m_students[index.row()];
    switch (role) {
    case IdRole:
        return student.id;
    case NameRole:
        return student.name;
    case DobRole:
        return student.dob;
    case DegreeRole:
        return student.degree;
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> StudentModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[NameRole] = "name";
    roles[DobRole] = "dob";
    roles[DegreeRole] = "degree";
    return roles;
}

void StudentModel::addStudent(const QString &id, const QString &name, const QString &dob, const QString &degree) {
    for (const Student &student : qAsConst(m_students)) {
        if (student.id == id) {
            qWarning() << "Student ID already exists!";
            return;
        }
    }

    beginInsertRows(QModelIndex(), m_students.count(), m_students.count());
    m_students.append({id, name, dob, degree});
    endInsertRows();
}

void StudentModel::deleteStudent(const QString &id) {
    for (int i = 0; i < m_students.size(); ++i) {
        if (m_students[i].id == id) {
            beginRemoveRows(QModelIndex(), i, i);
            m_students.removeAt(i);
            endRemoveRows();
            return;
        }
    }
}

void StudentModel::deleteAll() {
    beginResetModel();
    m_students.clear();
    endResetModel();
}
