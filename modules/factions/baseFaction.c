//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private string Name;

/////////////////////////////////////////////////////////////////////////////
public nomask string name()
{
    return Name;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setName(string newName)
{
    Name = newName;
}
