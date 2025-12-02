//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/realizations/npc.c";

object QuestItem;
object Quester;

/////////////////////////////////////////////////////////////////////////////
void SetQuestItem(object item)
{
    QuestItem = item;
}

/////////////////////////////////////////////////////////////////////////////
void SetQuester(object quester)
{
    Quester = quester;
}

/////////////////////////////////////////////////////////////////////////////
void DoMeetTheKingStuff()
{
    QuestItem.receiveEvent(Quester, "meetTheKing", this_object());
}

/////////////////////////////////////////////////////////////////////////////
void SureIWillServe()
{
    QuestItem.receiveEvent(Quester, "serveTheKing", this_object());
}

/////////////////////////////////////////////////////////////////////////////
void TimeToFoldSocks()
{
    QuestItem.receiveEvent(Quester, "ignoreTheKing", this_object());
}

/////////////////////////////////////////////////////////////////////////////
void ConfuseTheForcesOfEvil()
{
    QuestItem.receiveEvent(Quester, "hailToTheKing", this_object());
}

/////////////////////////////////////////////////////////////////////////////
void DoDebautchedThings()
{
    QuestItem.receiveEvent(Quester, "maybeNobodyWillNotice", this_object());
}
