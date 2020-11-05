//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

protected mapping environmentalElements = ([
    "terrain":([]),
    "interior": ([]),
    "feature": ([]),
    "building": ([]),
    "item": ([]),
    "door": ([]),
    "objects": ([]),
    "shop": 0,
    "cloned": 0,
    "description": ([]),
    "location text": ({ " is " }),
    "doors": ([]),
    "regions": ([])
]);

protected mapping aliasesToElements = ([]);
protected mapping exits = ([]);
protected mapping instances = ([]);

protected string uniqueIdentifier = 0;

/////////////////////////////////////////////////////////////////////////////
protected nomask void resetEnvironmentData()
{
    environmentalElements = ([
        "terrain":([]),
        "interior" : ([]),
        "feature" : ([]),
        "building" : ([]),
        "item" : ([]),
        "door": ([]),
        "objects" : ([]),
        "shop" : 0,
        "cloned" : 0,
        "description" : ([]),
        "location text" : ({ " is " }),
        "doors" : ([])
    ]);
    aliasesToElements = ([]);
    exits = ([]);
    instances = ([]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string capitalizeSentences(string message)
{
    string ret = regreplace(message, "^[a-z]", #'upper_case, 1);
        ret = regreplace(ret, "[.!?] +[a-z]", #'upper_case, 1);
            ret = regreplace(ret, "  ", " ");
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setIdentifier(string newIdentifier)
{
    uniqueIdentifier = newIdentifier;
}
