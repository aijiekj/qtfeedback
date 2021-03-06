/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the QtFeedback module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qdeclarativefileeffect_p.h"
/*!
    \internal
    \qmltype FileEffect
    \brief The FileEffect element represents feedback data stored in a file.
    \ingroup qml-feedback-api
    \inherits FeedbackEffect

    \snippet doc/src/snippets/declarative/declarative-feedback.qml File Effect

    \sa HapticsEffect, {QFeedbackActuator}
*/
QDeclarativeFileEffect::QDeclarativeFileEffect(QObject *parent)
    : QDeclarativeFeedbackEffect(parent)
{
    d = new QFeedbackFileEffect(this);
    setFeedbackEffect(d);
}

/*!
  \qmlproperty bool FileEffect::loaded

  This property is true if this feedback effect is loaded.
  */
bool QDeclarativeFileEffect::isLoaded() const
{
    return d->isLoaded();
}
void QDeclarativeFileEffect::setLoaded(bool v)
{
    if (v != d->isLoaded()) {
        d->setLoaded(v);
        emit loadedChanged();
    }
}

/*!
  \qmlproperty url FileEffect::source

  This property stores the URL for the feedback data.
  */
QUrl QDeclarativeFileEffect::source() const
{
    return d->source();
}
void QDeclarativeFileEffect::setSource(const QUrl & url)
{
    if (url != d->source()) {
        d->setSource(url);
        emit sourceChanged();
    }
}

/*!
  \qmlproperty list<string> FileEffect::supportedMimeTypes

  This property holds the MIME types supported for playing effects from a file.
  */
QStringList QDeclarativeFileEffect::supportedMimeTypes()
{
    return d->supportedMimeTypes();
}

/*!
    \qmlmethod  FileEffect::load()

    Makes sure that the file associated with the feedback object is loaded.
    \sa QFeedbackFileEffect::load()
*/
void QDeclarativeFileEffect::load()
{
    if (!isLoaded()) {
        d->load();
        emit loadedChanged();
    }
}

/*!
    \qmlmethod  FileEffect::unload()

    Makes sure that the file associated with the feedback object is unloaded.
    \sa QFeedbackFileEffect::unload()
*/
void QDeclarativeFileEffect::unload()
{
    if (isLoaded()) {
        d->unload();
        emit loadedChanged();
    }
}
