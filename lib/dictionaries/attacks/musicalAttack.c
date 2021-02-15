//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/dictionaries/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        ::reset(arg);
        setDamageType("musical");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int songIsQueued(object instrument)
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void playSong(object musician, object instrument, object foe)
{

}
