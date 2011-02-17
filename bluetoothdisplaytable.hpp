/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2011	Alexander Meinke <ameinke at online dot de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef BLUETOOTHDISPLAYTABLE_HPP
#define BLUETOOTHDISPLAYTABLE_HPP

#include <QDebug>
#include <QTableWidget>
#include <QHeaderView>
#include <QImage>
#include "primitive.hpp"


/*! BluetoothDisplayTable ist ein QTableWidget welches die Klick-Ereignisse
	auf QImage abbildet. QImage ermöglicht die Verarbeitung von Daten als
	Pixelinformationen. Diese können in Formaten wie .png oder .jpeg gespeichert
	werden.  */
class BluetoothDisplayTable : public QTableWidget, public QImage {
    Q_OBJECT
	QList<Primitive *> primitives;

public:
	/*! Initialisiert das QTableWidget und setzt unterscheidliche Eigenschaften. */
    explicit BluetoothDisplayTable(QWidget *parent = 0);

	/*! Gibt allozierten Speicher frei. */
	~BluetoothDisplayTable();

	/*! Fügt eine Figur (wie Rechteck oder Linie) auf dem Display hinzu.
		\param primitive Geometrische Figur */
	void addPrimitive(Primitive *);

	/*! Gibt die Anzahl der auf dem Display befindlichen Figuren zurück.
		\return Anzahl der Figuren */
	unsigned short getPrimitiveSize();

signals:

private slots:
	/*! Die Signale cellClicked und cellEntered selektieren eine Zelle in
		QTableWidget und setzen ein Bit in QImage.
		\param row Y
		\param column X */
	void cellSelected(int, int); // NOT a slot (signal?)

public slots:
	/*! openImage öffnet eine Datei als QImage und selektiert die entsprechenden
		Zellen in QTableWidget.
		\param file Datei welche geöffnet werden soll. */
	void openImage(QString);

	/*! saveImage speichert QImage im angegeben Format. Das Format wird durch
		die Dateiendung definiert.
		\param file Datei in die gespeichert werden soll. (z.B. example.png) */
	void saveImage(QString);
};

#endif // BLUETOOTHDISPLAYTABLE_HPP
