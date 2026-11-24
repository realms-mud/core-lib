//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/investigationRoom.c";

/////////////////////////////////////////////////////////////////////////////
protected void addClue(string name, string quest, string event, string account)
{
    addInvestigationClue(name, "/areas/minlach/quests/" + quest + ".c",
        event, account);
}
