//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/items/item.c";

private int ThrowOnDrop;

protected void Setup()
{
    set("name", "book");
    set("value", 50);
    set("weight", 1);
}

public varargs int drop(int silently)
{
    if (ThrowOnDrop)
    {
        raise_error("Test trade drop failure.\n");
    }
    return 1;
}

public void testThrowOnDrop()
{
    ThrowOnDrop = 1;
}
