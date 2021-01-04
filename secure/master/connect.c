//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

/////////////////////////////////////////////////////////////////////////////
public nomask object connect()
{
    object ret;
    string errorMessage;

    errorMessage = catch (ret = clone_object("secure/login"));
    write("\n");
    if (errorMessage)
    {
        write(errorMessage + "\n");
        ret =0;
    }
    return ret;
}
