//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    markAsCaveRoom();
    underCityRoom::Setup();
    setShortDescription("The worked passage gives way to rough limestone "
        "and a low, damp cavern.");
}

/////////////////////////////////////////////////////////////////////////////
public int moveFromIsAllowed(object user, object fromLocation)
{
    int ret = underCityRoom::moveFromIsAllowed(user, fromLocation);
    return ret;
}
