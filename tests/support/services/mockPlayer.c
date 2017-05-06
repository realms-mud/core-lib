//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/player.c";

/////////////////////////////////////////////////////////////////////////////
public int agePlayer(int amount)
{
    this_object()->materialAttributesHeartBeat(amount);
}