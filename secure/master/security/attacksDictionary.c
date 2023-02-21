//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/secure/master/security/priviledgeGroup.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void applyGroupDetails()
{
    setName("/lib/dictionaries/attacksDictionary");
    addPermission("/lib/dictionaries/attacks", Read);

    addPriviledgedEfun("get_dir");
    addPriviledgedEfun("file_size");
}
