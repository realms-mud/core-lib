//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

//---------------------------------------------------------------------------
/*
 * This function is called every time a player connects.
 * input_to() can't be called from here.
 */
object connect()
{
    object ob;
    string ret;

    ret = catch (ob = clone_object("secure/login"));
    write("\n");
    if (ret)
    {
        write(ret + "\n");
        return 0;
    }
    return ob;
}
