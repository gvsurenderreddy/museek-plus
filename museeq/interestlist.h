/* museeq - a Qt client to museekd
 *
 * Copyright (C) 2003-2004 Hyriand <hyriand@thegraveyard.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef INTERESTLIST_H
#define INTERESTLIST_H

#include <QWidget>

class InterestListView;
class QLineEdit;
class QMenu;

class InterestList : public QWidget {
	Q_OBJECT
public:
	InterestList(const QString&, QWidget* = 0, const char* = 0);
	QLineEdit* mEntry;

public slots:
	void added(const QString&);
	void removed(const QString&);
	void slotDoAddInterest();
	void slotDoAddHatedInterest();
	void slotDoRemoveInterest();
	void slotDoRemoveHatedInterest();
signals:
	void add(const QString&);
	void remove(const QString&);
	void recommend(const QString&);

private:

protected:
	QMenu *mPopup;
	QString mPopped;
	InterestListView *mListView ;
};

#endif // INTERESTLIST_H
