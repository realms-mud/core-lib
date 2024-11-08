//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/dictionaries/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setDamageType("musical");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int songIsQueued(object initiator)
{
    return initiator && initiator->hasActiveCompositeResearch();
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void playSong(object musician, object instrument, object foe)
{
    object song = musician->activeCompositeResearch();
    if (song)
    {
        song->executeCompositeResearch(musician);
    }
}
