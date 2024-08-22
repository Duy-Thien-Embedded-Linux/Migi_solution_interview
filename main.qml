import QtQuick 6.2
import QtQuick.Controls 6.2
import QtQuick.Layouts 1.15

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "Student Management"

    ColumnLayout {
        anchors.fill: parent
        spacing: 10

        // Input Fields
        RowLayout {
            spacing: 10
            TextField {
                id: studentIdInput
                placeholderText: "Student ID"
            }
            TextField {
                id: fullNameInput
                placeholderText: "Full Name"
            }
            TextField {
                id: dobInput
                placeholderText: "Date of Birth"
            }
            ComboBox {
                id: degreeInput
                model: ["Bachelor", "Master", "PhD"]
            }
        }

        // Buttons
        RowLayout {
            spacing: 10
            Button {
                text: "Add Student"
                onClicked: studentModel.addStudent(studentIdInput.text, fullNameInput.text, dobInput.text, degreeInput.currentText)
            }
            Button {
                text: "Delete All"
                onClicked: studentModel.deleteAll()
            }
        }

        // Student List
        ListView {
            Layout.fillWidth: true
            Layout.fillHeight: true
            model: studentModel
            spacing: 1

            delegate: Rectangle {
                height: 40
                width: ListView.view.width
                color: index % 2 === 0 ? "lightgray" : "white"
                border.color: "gray"

                Row {
                    anchors.fill: parent
                    spacing: 10

                    Text {
                        width: 100
                        text: model.id
                        verticalAlignment: Text.AlignVCenter
                    }
                    Text {
                        width: 200
                        text: model.name
                        verticalAlignment: Text.AlignVCenter
                    }
                    Text {
                        width: 150
                        text: model.dob
                        verticalAlignment: Text.AlignVCenter
                    }
                    Text {
                        width: 150
                        text: model.degree
                        verticalAlignment: Text.AlignVCenter
                    }
                    Button {
                        text: "Delete"
                        onClicked: studentModel.deleteStudent(model.id)
                    }
                }
            }
        }
    }
}
