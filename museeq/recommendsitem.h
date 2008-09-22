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

#ifndef RECOMMENDSITEM_H
#define RECOMMENDSITEM_H

#include <QTreeWidget>

class RecommendsView;

class RecommendsItem : public QTreeWidgetItem {
public:
	RecommendsItem(RecommendsView*, const QString&, unsigned int);

	int compare(QTreeWidgetItem*, int, bool) const;

	QString interest() const;

	bool operator<(const QTreeWidgetItem & other) const;
private:
	QString mInterest;
	unsigned int mNum;
};

#endif // RECOMMENDSITEM_H
