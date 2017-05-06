//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private int NumTimesCalled;

/////////////////////////////////////////////////////////////////////////////
public int TimesOnAttackReceived()
{
    return NumTimesCalled;
}

/////////////////////////////////////////////////////////////////////////////
public void onAttack(object caller)
{
    NumTimesCalled++;
}
