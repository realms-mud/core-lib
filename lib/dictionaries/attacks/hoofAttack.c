//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/dictionaries/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        ::reset(arg);
        setDamageType("physical");
        addHitDictionary(({
            "stomp", "trample", "pummel", "pound", "smack", "assault" }));

        addSimileDictionary(({
            "smashing into ##TargetPossessive## ##BodyPart##", "repeatedly in "
            "the ##BodyPart##" }));

        addMissMessage("##AttackerName## ##Infinitive::rear## up wildly and "
            "##Infinitive::paw## at the air with ##AttackerPossessive## hooves.");

        addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
            "##SimileDictionary## with ##AttackerPossessive## hooves.", "1-150");
    }
}
