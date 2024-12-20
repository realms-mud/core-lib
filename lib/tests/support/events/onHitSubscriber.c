//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private int NumTimesCalled;
private mapping *hitData = ({});

/////////////////////////////////////////////////////////////////////////////
public void ClearEvents()
{
    NumTimesCalled = 0;
    hitData = ({});
}

/////////////////////////////////////////////////////////////////////////////
public int TimesOnHitEventReceived()
{
    return NumTimesCalled;
}

/////////////////////////////////////////////////////////////////////////////
public mapping *OnHitEventData()
{
    return hitData + ({});
}

/////////////////////////////////////////////////////////////////////////////
public void onHit(object caller, mapping data)
{
    NumTimesCalled++;
    hitData += ({ data });
}
