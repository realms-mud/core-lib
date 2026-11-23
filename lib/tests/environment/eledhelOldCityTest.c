//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/tests/environment/eledhelCountrysideTest.c";

void Init()
{
    selectTestMethods(({
        "OldCityInstitutionsConnectToThePlaza",
        "AegisHallAndAcademyAreConnectedAndStaffed",
        "WerricOutpostProvidesKnightlyTraining",
        "GoldenFlaskHostsTravelers",
        "OldCityMerchantRowServesResidents",
        "OldCitySupportingBusinessesConnectToTheirStreets",
        "RemainingOldCityStorefrontsAreStockedAndStaffed",
        "ConnectedOldCityStreetsHaveConversationalResidents",
        "PlazaHasPublicDirectionsAndStaff",
        "EveryOldCityInteriorLoads"
    }));
}

void Setup()
{
    Region = 0;
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("bob");
    Player.addCommands();
    Player.colorConfiguration("none");
    Harvested = ({});
    Spawned = ({});
}

private object findResident(object room, string residentName)
{
    object ret = 0;
    if (objectp(room) && stringp(residentName))
    {
        foreach (object resident in all_inventory(room))
        {
            if (resident != Player && resident->id(residentName))
            {
                ret = resident;
            }
        }
    }
    return ret;
}

void OldCityInstitutionsConnectToThePlaza()
{
    object plaza = load_object("/areas/eledhel/central-city/13x5.c");
    object hall = load_object("/areas/eledhel/central-city/11x4.c");
    object academy = load_object("/areas/eledhel/central-city/11x6.c");
    object inn = load_object("/areas/eledhel/central-city/13x4.c");
    object temple = load_object("/areas/eledhel/central-city/13x6.c");

    ExpectEq("/areas/eledhel/central-city/13x6.c",
        plaza->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/central-city/13x4.c",
        plaza->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/eledhel/central-city/12x5.c",
        plaza->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/eledhel/central-city/14x5.c",
        plaza->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/central-city/11x5.c",
        hall->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/central-city/11x5.c",
        academy->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/eledhel/central-city/13x5.c",
        inn->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/central-city/13x5.c",
        temple->getExitDirections()["default"]["south"]);
    ExpectTrue(hall->isEnvironmentalElement("plank door"));
    ExpectTrue(academy->isEnvironmentalElement("plank door"));
    ExpectTrue(inn->isEnvironmentalElement("plank door"));
    ExpectTrue(temple->isEnvironmentalElement("plank door"));

    Harvested += ({ plaza, hall, academy, inn, temple });
}

void AegisHallAndAcademyAreConnectedAndStaffed()
{
    object hall = clone_object(
        "/areas/eledhel/central-city/aegis-hall/0x0.c");
    object drillFloor = clone_object(
        "/areas/eledhel/central-city/aegis-academy/0x0.c");
    object recruiter = 0;
    object cadet = 0;

    move_object(Player, hall);
    foreach (object resident in all_inventory(hall))
    {
        if (resident != Player && resident->id("Lethar"))
        {
            recruiter = resident;
            Spawned += ({ resident });
        }
    }

    move_object(Player, drillFloor);
    foreach (object resident in all_inventory(drillFloor))
    {
        if (resident != Player && resident->id("Aegis cadet"))
        {
            cadet = resident;
            Spawned += ({ resident });
        }
    }

    ExpectTrue(objectp(recruiter));
    ExpectTrue(objectp(cadet));
    ExpectEq("Aegis Guard", recruiter->teachingGuild());
    ExpectTrue(sizeof(recruiter->teachableResearch()) > 0);
    ExpectTrue(recruiter->hasTopic("enrollment") > -1);
    ExpectTrue(cadet->hasTopic("training") > -1);
    ExpectTrue(drillFloor->isEnvironmentalElement("training dummy"));
    ExpectTrue(drillFloor->isEnvironmentalElement("weapon rack"));

    Harvested += ({ hall, drillFloor });
}

void WerricOutpostProvidesKnightlyTraining()
{
    object entry = clone_object(
        "/areas/eledhel/central-city/triumvirate-temple/0x0.c");
    object passage = clone_object(
        "/areas/eledhel/central-city/triumvirate-temple/0x1.c");
    object greatHall = clone_object(
        "/areas/eledhel/central-city/triumvirate-temple/1x1.c");
    object instructor = 0;

    ExpectEq("/areas/eledhel/central-city/triumvirate-temple/0x1.c",
        entry->getExitDirections()["default"]["down"]);
    ExpectEq("/areas/eledhel/central-city/triumvirate-temple/0x0.c",
        passage->getExitDirections()["default"]["up"]);
    ExpectEq("/areas/eledhel/central-city/triumvirate-temple/1x1.c",
        passage->getExitDirections()["default"]["south"]);

    move_object(Player, greatHall);
    foreach (object resident in all_inventory(greatHall))
    {
        if (resident != Player && resident->id("Caldrin"))
        {
            instructor = resident;
            Spawned += ({ resident });
        }
    }

    ExpectTrue(objectp(instructor));
    ExpectEq("Werric Knight", instructor->teachingGuild());
    ExpectTrue(sizeof(instructor->teachableResearch()) > 0);
    ExpectTrue(instructor->hasTopic("enrollment") > -1);
    ExpectTrue(greatHall->isEnvironmentalElement("long table"));
    ExpectTrue(greatHall->isEnvironmentalElement("book shelf"));

    Harvested += ({ entry, passage, greatHall });
}

void GoldenFlaskHostsTravelers()
{
    object commonRoom = clone_object(
        "/areas/eledhel/central-city/golden-flask/0x0.c");
    object guestPassage = clone_object(
        "/areas/eledhel/central-city/golden-flask/0x1.c");
    object guestRoom = clone_object(
        "/areas/eledhel/central-city/golden-flask/1x1.c");
    object innkeeper = 0;

    move_object(Player, commonRoom);
    foreach (object resident in all_inventory(commonRoom))
    {
        if (resident != Player && resident->id("Marel"))
        {
            innkeeper = resident;
            Spawned += ({ resident });
        }
    }

    ExpectTrue(objectp(innkeeper));
    ExpectTrue(innkeeper->hasTopic("the inn") > -1);
    ExpectTrue(commonRoom->isEnvironmentalElement("long table"));
    ExpectTrue(commonRoom->isEnvironmentalElement("hearth"));
    ExpectEq("/areas/eledhel/central-city/golden-flask/1x1.c",
        guestPassage->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/central-city/golden-flask/0x1.c",
        guestRoom->getExitDirections()["default"]["west"]);
    ExpectTrue(guestRoom->isEnvironmentalElement("canopy bed"));

    Harvested += ({ commonRoom, guestPassage, guestRoom });
}

void PlazaHasPublicDirectionsAndStaff()
{
    object plaza = clone_object("/areas/eledhel/central-city/13x5.c");
    object crier = 0;

    move_object(Player, plaza);
    foreach (object resident in all_inventory(plaza))
    {
        if (resident != Player && resident->id("Eledhel crier"))
        {
            crier = resident;
            Spawned += ({ resident });
        }
    }

    ExpectTrue(objectp(crier));
    ExpectTrue(crier->hasTopic("the institutions") > -1);
    ExpectTrue(plaza->isEnvironmentalElement("bench"));
    ExpectTrue(plaza->isEnvironmentalElement("notice board"));

    Harvested += ({ plaza });
}

void OldCityMerchantRowServesResidents()
{
    object leatherEntrance = load_object(
        "/areas/eledhel/central-city/14x0.c");
    object tailorEntrance = load_object(
        "/areas/eledhel/central-city/14x1.c");
    object leatherShop = clone_object(
        "/areas/eledhel/central-city/leather-merchant/0x0.c");
    object leatherWorkshop = load_object(
        "/areas/eledhel/central-city/leather-merchant/1x0.c");
    object tailorShop = clone_object(
        "/areas/eledhel/central-city/old-city-tailor/0x0.c");
    object fittingRoom = load_object(
        "/areas/eledhel/central-city/old-city-tailor/1x0.c");
    object leatherworker = 0;
    object leatherShopper = 0;
    object tailor = 0;
    object tailorCustomer = 0;

    ExpectEq("/areas/eledhel/central-city/leather-merchant/0x0.c",
        leatherEntrance->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/central-city/old-city-tailor/0x0.c",
        tailorEntrance->getExitDirections()["default"]["east"]);
    ExpectTrue(leatherEntrance->isEnvironmentalElement("plank door"));
    ExpectTrue(tailorEntrance->isEnvironmentalElement("plank door"));
    ExpectEq("/areas/eledhel/central-city/14x0.c",
        leatherShop->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/eledhel/central-city/14x1.c",
        tailorShop->getExitDirections()["default"]["west"]);
    ExpectTrue(leatherShop->isEnvironmentalElement("plank door"));
    ExpectTrue(tailorShop->isEnvironmentalElement("plank door"));

    ExpectEq("medium armor", leatherShop->getShop()->shopSubType());
    ExpectTrue(sizeof(leatherShop->getShop()->storeInventory()) > 0);
    ExpectEq("/areas/eledhel/central-city/leather-merchant/1x0.c",
        leatherShop->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/central-city/leather-merchant/0x0.c",
        leatherWorkshop->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/eledhel/central-city/old-city-tailor/1x0.c",
        tailorShop->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/central-city/old-city-tailor/0x0.c",
        fittingRoom->getExitDirections()["default"]["west"]);

    move_object(Player, leatherShop);
    foreach (object resident in all_inventory(leatherShop))
    {
        if (resident != Player && resident->id("Tavren"))
        {
            leatherworker = resident;
            Spawned += ({ resident });
        }
        else if (resident != Player && resident->id("Rovin"))
        {
            leatherShopper = resident;
            Spawned += ({ resident });
        }
    }

    move_object(Player, tailorShop);
    foreach (object resident in all_inventory(tailorShop))
    {
        if (resident != Player && resident->id("Selyra"))
        {
            tailor = resident;
            Spawned += ({ resident });
        }
        else if (resident != Player && resident->id("Olyne"))
        {
            tailorCustomer = resident;
            Spawned += ({ resident });
        }
    }

    ExpectTrue(objectp(leatherworker));
    ExpectTrue(leatherworker->hasTopic("leather goods") > -1);
    ExpectTrue(objectp(leatherShopper));
    ExpectTrue(leatherShopper->hasTopic("travel gear") > -1);
    ExpectTrue(objectp(tailor));
    ExpectTrue(tailor->hasTopic("formal clothing") > -1);
    ExpectEq("clothing", tailorShop->getShop()->shopSubType());
    ExpectTrue(sizeof(tailorShop->getShop()->storeInventory()) > 0);
    ExpectTrue(objectp(tailorCustomer));
    ExpectTrue(tailorCustomer->hasTopic("work clothes") > -1);
    ExpectTrue(leatherWorkshop->isEnvironmentalElement("workbench"));
    ExpectTrue(fittingRoom->isEnvironmentalElement("mirror"));

    Harvested += ({ leatherShop, tailorShop });
}

void OldCitySupportingBusinessesConnectToTheirStreets()
{
    object furrierStreet = load_object(
        "/areas/eledhel/central-city/12x0.c");
    object serviceStreet = load_object(
        "/areas/eledhel/central-city/12x1.c");
    object furrier = clone_object(
        "/areas/eledhel/central-city/furrier/0x0.c");
    object tavern = clone_object(
        "/areas/eledhel/central-city/tavern/0x0.c");
    object brewery = clone_object(
        "/areas/eledhel/central-city/brewery/0x0.c");
    object theatreFoyer = clone_object(
        "/areas/eledhel/central-city/theater/0x0.c");
    object theatre = clone_object(
        "/areas/eledhel/central-city/theater/1x0.c");
    object furrierResident = 0;
    object furrierCustomer = 0;
    object tavernkeeper = 0;
    object tavernGuest = 0;
    object brewer = 0;
    object breweryCustomer = 0;
    object manager = 0;
    object performer = 0;

    ExpectEq("/areas/eledhel/central-city/furrier/0x0.c",
        furrierStreet->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/central-city/tavern/0x0.c",
        furrierStreet->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/eledhel/central-city/brewery/0x0.c",
        serviceStreet->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/central-city/theater/0x0.c",
        serviceStreet->getExitDirections()["default"]["west"]);
    ExpectTrue(furrierStreet->isEnvironmentalElement("plank door"));
    ExpectTrue(serviceStreet->isEnvironmentalElement("plank door"));
    ExpectEq("/areas/eledhel/central-city/12x0.c",
        furrier->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/eledhel/central-city/12x0.c",
        tavern->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/central-city/12x1.c",
        brewery->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/eledhel/central-city/12x1.c",
        theatreFoyer->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/central-city/theater/0x0.c",
        theatre->getExitDirections()["default"]["south"]);
    ExpectEq("clothing", furrier->getShop()->shopSubType());
    ExpectTrue(sizeof(furrier->getShop()->storeInventory()) > 0);
    ExpectTrue(sizeof(tavern->getShop()->storeInventory()) > 0);
    ExpectTrue(sizeof(brewery->getShop()->storeInventory()) > 0);

    move_object(Player, furrier);
    foreach (object resident in all_inventory(furrier))
    {
        if (resident != Player && resident->id("Othrel"))
        {
            furrierResident = resident;
            Spawned += ({ resident });
        }
        else if (resident != Player && resident->id("Mavren"))
        {
            furrierCustomer = resident;
            Spawned += ({ resident });
        }
    }

    move_object(Player, tavern);
    foreach (object resident in all_inventory(tavern))
    {
        if (resident != Player && resident->id("Dalen"))
        {
            tavernkeeper = resident;
            Spawned += ({ resident });
        }
        else if (resident != Player && resident->id("Sira"))
        {
            tavernGuest = resident;
            Spawned += ({ resident });
        }
    }

    move_object(Player, brewery);
    foreach (object resident in all_inventory(brewery))
    {
        if (resident != Player && resident->id("Calven"))
        {
            brewer = resident;
            Spawned += ({ resident });
        }
        else if (resident != Player && resident->id("Korin"))
        {
            breweryCustomer = resident;
            Spawned += ({ resident });
        }
    }

    move_object(Player, theatre);
    foreach (object resident in all_inventory(theatre))
    {
        if (resident != Player && resident->id("Lethwyn"))
        {
            manager = resident;
            Spawned += ({ resident });
        }
        else if (resident != Player && resident->id("Vesra"))
        {
            performer = resident;
            Spawned += ({ resident });
        }
    }

    ExpectTrue(objectp(furrierResident));
    ExpectTrue(furrierResident->hasTopic("pelts") > -1);
    ExpectTrue(objectp(furrierCustomer));
    ExpectTrue(furrierCustomer->hasTopic("travel gear") > -1);
    ExpectTrue(objectp(tavernkeeper));
    ExpectTrue(tavernkeeper->hasTopic("gate street") > -1);
    ExpectTrue(objectp(tavernGuest));
    ExpectTrue(tavernGuest->hasTopic("market work") > -1);
    ExpectTrue(objectp(brewer));
    ExpectTrue(brewer->hasTopic("cider") > -1);
    ExpectTrue(objectp(breweryCustomer));
    ExpectTrue(breweryCustomer->hasTopic("provisions") > -1);
    ExpectTrue(objectp(manager));
    ExpectTrue(manager->hasTopic("performances") > -1);
    ExpectTrue(objectp(performer));
    ExpectTrue(performer->hasTopic("road songs") > -1);

    ExpectTrue(theatre->isEnvironmentalElement("bench"));
    Harvested += ({ furrier, tavern, brewery, theatreFoyer, theatre });
}

void RemainingOldCityStorefrontsAreStockedAndStaffed()
{
    string *streetPaths = ({
        "/areas/eledhel/central-city/17x0.c",
        "/areas/eledhel/central-city/17x1.c",
        "/areas/eledhel/central-city/20x0.c",
        "/areas/eledhel/central-city/20x1.c"
    });
    string *shopPaths = ({
        "/areas/eledhel/central-city/old-city-swordsmith/0x0.c",
        "/areas/eledhel/central-city/old-city-saddlery/0x0.c",
        "/areas/eledhel/central-city/old-city-armorer/0x0.c",
        "/areas/eledhel/central-city/old-city-tailor-two/0x0.c",
        "/areas/eledhel/central-city/old-city-dagger-smith/0x0.c",
        "/areas/eledhel/central-city/old-city-provisioner/0x0.c",
        "/areas/eledhel/central-city/old-city-hammer-smith/0x0.c",
        "/areas/eledhel/central-city/wayfarer-inn/0x0.c"
    });
    string *staffNames = ({
        "Tirwen", "Myrwen", "Barad", "Nethwen",
        "Hethor", "Meleth", "Gorwen", "Teren"
    });
    string *staffTopics = ({
        "sword orders", "harnesses", "armor orders", "everyday clothing",
        "dagger work", "provisions", "hammers", "lodging"
    });
    string *customerNames = ({
        "Gethen", "Saran", "Nereth", "Rillan",
        "Dareth", "Orwen", "Aelion", "Lethen"
    });
    string *customerTopics = ({
        "commission", "cart delivery", "guard repairs", "office clothes",
        "watch duty", "market list", "stonework", "north road"
    });
    string *eastExits = ({
        shopPaths[0], shopPaths[2], shopPaths[5], shopPaths[7]
    });
    string *westExits = ({
        shopPaths[1], shopPaths[3], shopPaths[4], shopPaths[6]
    });

    for (int index = 0; index < sizeof(streetPaths); index++)
    {
        object street = load_object(streetPaths[index]);
        ExpectEq(eastExits[index],
            street->getExitDirections()["default"]["east"]);
        ExpectEq(westExits[index],
            street->getExitDirections()["default"]["west"]);
        ExpectTrue(street->isEnvironmentalElement("plank door"));
        Harvested += ({ street });
    }

    for (int shopIndex = 0; shopIndex < sizeof(shopPaths); shopIndex++)
    {
        object shop = clone_object(shopPaths[shopIndex]);
        Harvested += ({ shop });
        ExpectTrue(objectp(shop->getShop()), shopPaths[shopIndex]);
        ExpectTrue(sizeof(shop->getShop()->storeInventory()) > 0,
            shopPaths[shopIndex]);
        ExpectTrue(shop->isEnvironmentalElement("plank door"));

        move_object(Player, shop);
        object staff = findResident(shop, staffNames[shopIndex]);
        object customer = findResident(shop, customerNames[shopIndex]);
        ExpectTrue(objectp(staff), staffNames[shopIndex]);
        ExpectTrue(objectp(customer), customerNames[shopIndex]);
        if (objectp(staff))
        {
            Spawned += ({ staff });
            ExpectTrue(staff->hasTopic(staffTopics[shopIndex]) > -1,
                staffNames[shopIndex]);
        }
        if (objectp(customer))
        {
            Spawned += ({ customer });
            ExpectTrue(customer->hasTopic(customerTopics[shopIndex]) > -1,
                customerNames[shopIndex]);
        }
    }
}

void ConnectedOldCityStreetsHaveConversationalResidents()
{
    string *roomPaths = ({
        "/areas/eledhel/central-city/0x5.c",
        "/areas/eledhel/central-city/1x5.c",
        "/areas/eledhel/central-city/2x5.c",
        "/areas/eledhel/central-city/3x5.c",
        "/areas/eledhel/central-city/4x5.c",
        "/areas/eledhel/central-city/5x5.c",
        "/areas/eledhel/central-city/6x5.c",
        "/areas/eledhel/central-city/7x5.c",
        "/areas/eledhel/central-city/8x5.c",
        "/areas/eledhel/central-city/9x5.c",
        "/areas/eledhel/central-city/10x5.c",
        "/areas/eledhel/central-city/11x4.c",
        "/areas/eledhel/central-city/11x5.c",
        "/areas/eledhel/central-city/11x6.c",
        "/areas/eledhel/central-city/12x0.c",
        "/areas/eledhel/central-city/12x1.c",
        "/areas/eledhel/central-city/12x2.c",
        "/areas/eledhel/central-city/12x3.c",
        "/areas/eledhel/central-city/12x4.c",
        "/areas/eledhel/central-city/12x5.c",
        "/areas/eledhel/central-city/12x6.c",
        "/areas/eledhel/central-city/12x7.c",
        "/areas/eledhel/central-city/12x8.c",
        "/areas/eledhel/central-city/12x9.c",
        "/areas/eledhel/central-city/13x2.c",
        "/areas/eledhel/central-city/13x4.c",
        "/areas/eledhel/central-city/13x6.c",
        "/areas/eledhel/central-city/14x0.c",
        "/areas/eledhel/central-city/14x1.c",
        "/areas/eledhel/central-city/14x2.c",
        "/areas/eledhel/central-city/14x5.c",
        "/areas/eledhel/central-city/15x2.c",
        "/areas/eledhel/central-city/16x2.c",
        "/areas/eledhel/central-city/17x0.c",
        "/areas/eledhel/central-city/17x1.c",
        "/areas/eledhel/central-city/17x2.c",
        "/areas/eledhel/central-city/18x2.c",
        "/areas/eledhel/central-city/19x2.c",
        "/areas/eledhel/central-city/20x0.c",
        "/areas/eledhel/central-city/20x1.c",
        "/areas/eledhel/central-city/20x2.c"
    });
    string *residentNames = ({
        "Deren", "Alwen", "Mereth", "Rovan", "Selwen", "Taren",
        "Yalwen", "Wethen", "Ivran", "Sarneth", "Haeren", "Raeth",
        "Gwineth", "Haldor", "Faren", "Elmor", "Velwen", "Caranor",
        "Nethor", "Galeth", "Vardan", "Mineth", "Edreth", "Yeren",
        "Anwen", "Goven", "Estel", "Rianor", "Melwen", "Edran",
        "Selenel", "Arthen", "Calen", "Elen", "Hithen", "Thalion",
        "Siven", "Belen", "Norwen", "Ryneth", "Keldan"
    });
    string *topics = ({
        "western road", "flower baskets", "city routes", "cart wheels",
        "fresh bread", "goods by cart", "lamplight", "ledgers",
        "street music", "storehouse work", "watch patrol",
        "Aegis messages", "school day", "academy training",
        "winter cloaks", "handbills", "stage work", "letters",
        "records", "public square", "Werric order", "temple service",
        "city garden", "north road", "lodging", "work day", "faith",
        "leather trade", "tailoring", "study", "palace service",
        "stonework", "guard duty", "sword buying", "courier clothes",
        "cart repair", "street watch", "loading", "provisions", "inn",
        "deliveries"
    });

    ExpectEq(41, sizeof(roomPaths));
    ExpectEq(sizeof(roomPaths), sizeof(residentNames));
    ExpectEq(sizeof(roomPaths), sizeof(topics));
    for (int index = 0; index < sizeof(roomPaths); index++)
    {
        object room = clone_object(roomPaths[index]);
        Harvested += ({ room });
        ExpectTrue(sizeof(room->getExitDirections()["default"]) > 0,
            roomPaths[index]);
        move_object(Player, room);

        object resident = findResident(room, residentNames[index]);
        ExpectTrue(objectp(resident), residentNames[index]);
        if (objectp(resident))
        {
            Spawned += ({ resident });
            ExpectTrue(resident->hasTopic(topics[index]) > -1,
                residentNames[index]);
        }
    }
}

void EveryOldCityInteriorLoads()
{
    string *rooms = ({
        "/areas/eledhel/central-city/aegis-hall/0x0.c",
        "/areas/eledhel/central-city/aegis-hall/1x0.c",
        "/areas/eledhel/central-city/aegis-hall/0x1.c",
        "/areas/eledhel/central-city/aegis-hall/1x1.c",
        "/areas/eledhel/central-city/aegis-academy/0x0.c",
        "/areas/eledhel/central-city/aegis-academy/1x0.c",
        "/areas/eledhel/central-city/aegis-academy/0x1.c",
        "/areas/eledhel/central-city/triumvirate-temple/0x0.c",
        "/areas/eledhel/central-city/triumvirate-temple/0x1.c",
        "/areas/eledhel/central-city/triumvirate-temple/1x1.c",
        "/areas/eledhel/central-city/triumvirate-temple/1x2.c",
        "/areas/eledhel/central-city/golden-flask/0x0.c",
        "/areas/eledhel/central-city/golden-flask/1x0.c",
        "/areas/eledhel/central-city/golden-flask/0x1.c",
        "/areas/eledhel/central-city/golden-flask/1x1.c",
        "/areas/eledhel/central-city/leather-merchant/0x0.c",
        "/areas/eledhel/central-city/leather-merchant/1x0.c",
        "/areas/eledhel/central-city/old-city-tailor/0x0.c",
        "/areas/eledhel/central-city/old-city-tailor/1x0.c",
        "/areas/eledhel/central-city/furrier/0x0.c",
        "/areas/eledhel/central-city/furrier/1x0.c",
        "/areas/eledhel/central-city/tavern/0x0.c",
        "/areas/eledhel/central-city/tavern/1x0.c",
        "/areas/eledhel/central-city/brewery/0x0.c",
        "/areas/eledhel/central-city/brewery/1x0.c",
        "/areas/eledhel/central-city/theater/0x0.c",
        "/areas/eledhel/central-city/theater/1x0.c",
        "/areas/eledhel/central-city/old-city-swordsmith/0x0.c",
        "/areas/eledhel/central-city/old-city-swordsmith/1x0.c",
        "/areas/eledhel/central-city/old-city-saddlery/0x0.c",
        "/areas/eledhel/central-city/old-city-saddlery/1x0.c",
        "/areas/eledhel/central-city/old-city-armorer/0x0.c",
        "/areas/eledhel/central-city/old-city-armorer/1x0.c",
        "/areas/eledhel/central-city/old-city-tailor-two/0x0.c",
        "/areas/eledhel/central-city/old-city-tailor-two/1x0.c",
        "/areas/eledhel/central-city/old-city-dagger-smith/0x0.c",
        "/areas/eledhel/central-city/old-city-dagger-smith/1x0.c",
        "/areas/eledhel/central-city/old-city-provisioner/0x0.c",
        "/areas/eledhel/central-city/old-city-provisioner/1x0.c",
        "/areas/eledhel/central-city/old-city-hammer-smith/0x0.c",
        "/areas/eledhel/central-city/old-city-hammer-smith/1x0.c",
        "/areas/eledhel/central-city/wayfarer-inn/0x0.c",
        "/areas/eledhel/central-city/wayfarer-inn/0x1.c",
        "/areas/eledhel/central-city/wayfarer-inn/1x1.c"
    });

    foreach (string roomPath in rooms)
    {
        ExpectTrue(objectp(load_object(roomPath)), roomPath);
    }
}
