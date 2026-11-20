//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Aglaradan");
    short("Aglaradan, the quiet old archer");
    description("Aglaradan is an old, quiet man with an icy glare. "
        "His bow is worn from use, and his aim settles with scarcely "
        "a movement. He watches the approach as if no detail escapes him.");

    Gender("male");
    Race("maegenstryd");
}
