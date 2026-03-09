//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

object region;

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/areas/tol-dhurath/interiors/pedestal-chamber.c");
    addFeature("/areas/tol-dhurath/features/amethyst-floor.c");
    addFeature("/areas/tol-dhurath/features/amethyst-ceiling.c");
    addFeature("/areas/tol-dhurath/features/purple-liquid.c");

    setStateMachine("/areas/tol-dhurath/state-machine/obedience-quest.c");

    addExit("south", "/areas/tol-dhurath/temple-interior/pedestal-1x1.c");
    
    addDecorator("ruined interior east alcove south entry");
    addDecorator("ruined interior east alcove", "resistance rune placed");
    addDecorator("ruined interior east alcove", "first test");
    addDecorator("ruined interior east alcove", "second test");
    addDecorator("ruined interior east alcove", "third test");
    addDecorator("ruined interior east alcove", "fourth test");
    addDecorator("ruined interior east alcove", "fifth test");
    addDecorator("ruined interior east alcove", "sixth test");
    addDecorator("ruined interior east alcove", "seventh test");
}
