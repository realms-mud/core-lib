//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/guilds/baseGuild.c";

/////////////////////////////////////////////////////////////////////////////
public void SetupGuild()
{
    guildName("fake fighter");
    addRank("neophyte", (["name":"neophyte", "title" : "the title of titliness", "pretitle" : "Neophyte", "next rank" : "acolyte"]));
    addRank("acolyte", (["name":"acolyte", "title" : "the title of titliness", "pretitle" : "Acolyte", "previous rank" : "neophyte", "next rank" : "blargyte", "delay for next promotion" : 1]));
    addRank("blargyte", (["name":"blargyte", "title" : "the title of titliness", "pretitle" : "Blargyte"]));
    setDefaultRank("neophyte");
}
