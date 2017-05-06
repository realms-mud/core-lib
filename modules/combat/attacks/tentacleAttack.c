inherit "/lib/modules/combat/attacks/baseAttack.c";

public void init()
{
    ::init();
    setDamageType("physical");
    addHitDictionary(({
        "crush", "squeeze", "crunch", "strangle", "constrict", "clutch",
        "grip"}));

    addSimileDictionary(({
        "squashing ##TargetPossessive## ##BodyPart## tightly",
        "on ##TargetPossessive## ##BodyPart## like a tourniquet",
        "with a ##BodyPart##-choking force" }));
        
    addMissMessage("##AttackerName## ##Infinitive::wave## ##AttackerPossessive##"
        " tentacles wildly around!");
    
    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
        "##SimileDictionary## with ##AttackerPossessive## tentacles.",
        "1-50");
}




