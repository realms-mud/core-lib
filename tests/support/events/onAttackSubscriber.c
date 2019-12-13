//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private int NumTimesAttack;
private int NumTimesAttacked;

/////////////////////////////////////////////////////////////////////////////
public int TimesOnAttackReceived()
{
    return NumTimesAttack;
}

/////////////////////////////////////////////////////////////////////////////
public int TimesOnAttackedReceived()
{
    return NumTimesAttacked;
}

/////////////////////////////////////////////////////////////////////////////
public void onAttack(object caller)
{
    NumTimesAttack++;
}

/////////////////////////////////////////////////////////////////////////////
public void onAttacked(object caller)
{
    NumTimesAttacked++;
}
