//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

int attack = 0;
int attacked = 0;

/////////////////////////////////////////////////////////////////////////////
public void onAttack()
{
    attack++;
}

/////////////////////////////////////////////////////////////////////////////
public void onAttacked()
{
    attacked++;
}

/////////////////////////////////////////////////////////////////////////////
public int wasAttacker()
{
    return attack;
}

/////////////////////////////////////////////////////////////////////////////
public int wasAttacked()
{
    return attacked;
}
