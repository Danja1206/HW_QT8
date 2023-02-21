#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QWidget>
#include <QGridLayout>
#include <QTreeView>
#include <QComboBox>
#include <QPushButton>
#include <QStandardItemModel>
#include <QApplication>
#include <QFileSystemModel>
#include <QMouseEvent>

Q_PROPERTY(QStandardItemModel *model READ getCurrentModel WRITE setNewModel)


class FileManager : public QWidget
{
    Q_OBJECT
public:
    explicit FileManager(QWidget *parent = nullptr);
    QStandardItemModel *getCurrentModel()const
    {
        return model;
    }
    void show();
    void hide();
    QString filePath;
    QTreeView *tree;

private:
    QStandardItemModel *model;
    QGridLayout *gridLay;
    QFileSystemModel *dirmodel;

protected:
public slots:
    void test(const QModelIndex& index);

};

#endif // FILEMANAGER_H
