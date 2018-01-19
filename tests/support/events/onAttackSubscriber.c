//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
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
