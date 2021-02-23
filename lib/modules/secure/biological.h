//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef biologicalModule_h
#define biologicalModule_h

private int intoxicated;
private int stuffed;
private int drugged;
private int soaked;
private int headache;

private nosave int maxHeadache = 30;

/////////////////////////////////////////////////////////////////////////////
static nomask void loadBiological(mapping data, object persistence)
{
    if (isValidPersistenceObject(persistence))
    {
        intoxicated = persistence->extractSaveData("intoxicated", data);
        stuffed = persistence->extractSaveData("stuffed", data);
        drugged = persistence->extractSaveData("drugged", data);
        soaked = persistence->extractSaveData("soaked", data);
        headache = persistence->extractSaveData("headache", data);
    }
}

/////////////////////////////////////////////////////////////////////////////
static nomask mapping sendBiological()
{
    return ([
        "intoxicated": intoxicated,
        "stuffed": stuffed,
        "drugged": drugged,
        "soaked": soaked,
        "headache": headache,
    ]);
}

#endif
