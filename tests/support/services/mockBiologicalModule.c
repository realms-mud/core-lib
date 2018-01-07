//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing";

private int useBiological = 0;

/////////////////////////////////////////////////////////////////////////////
public void ToggleMockBiological()
{
    useBiological = !useBiological;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int biologicalBonusTo(string bonus)
{
    return useBiological * -2;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int Intoxicated()
{
    return useBiological * 10;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int Drugged()
{
    return useBiological * 10;
}

