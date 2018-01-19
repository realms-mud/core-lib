//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/combat/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        ::reset(arg);
        setDamageType("physical");
        addHitDictionary(({
            "bash", "slam", "slap", "pummel", "crush", "pound", "punch", "smack",
            "assault" }));

        addSimileDictionary(({
            "smashing ##TargetPossessive## ##BodyPart## soundly", "repeatedly in "
            "the ##BodyPart##", "with a ##BodyPart##-shattering force" }));

        addMissMessage("##AttackerName## ##Infinitive::flail## wildly! Very theatric.");

        addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
            "##SimileDictionary##.", "1-50");
    }
}




