//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Ornate staff");
    set("short", "Ornate staff");
    set("aliases", ({ "staff", "ornate staff" }));
    set("blueprint", "ornate staff");
}
