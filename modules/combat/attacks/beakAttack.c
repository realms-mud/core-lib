//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
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
            "snip", "clip", "pinch", "poke", "tear", "wrend", "bite" }));

        addSimileDictionary(({
            "on ##TargetPossessive## ##BodyPart##", "repeatedly in "
            "the ##BodyPart##", "viciously" }));

        addMissMessage("##AttackerName## ##Infinitive::snap## ##AttackerPossessive##"
            " beak menacingly, but harmlessly.");

        addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
            "##SimileDictionary## with ##AttackerPossessive## beak.", "1-50");
    }
}




