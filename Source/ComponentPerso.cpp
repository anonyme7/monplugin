/*
  ==============================================================================

    ComponentPerso.cpp
    Created: 19 Apr 2025 9:17:10pm
    Author:  olivier

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ComponentPerso.h"
#include "PluginEditor.h"

//==============================================================================
ComponentPerso::ComponentPerso()
{
    setSize(50, 50);

}

ComponentPerso::~ComponentPerso()
{
}

void ComponentPerso::paint (juce::Graphics& g)
{
    if (isSelected)
    {
        g.setColour(juce::Colours::red);
        g.drawRect(getLocalBounds(), 2.0f); // Bordure rouge, �paisseur 2 pixels
    }
}

void ComponentPerso::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}


void ComponentPerso :: mouseDown(const juce::MouseEvent& event)
{
    if (auto* editor = dynamic_cast<MonpluginAudioProcessorEditor*>(getParentComponent()))
        editor->selectComponent(this);

    if (event.mods.isRightButtonDown())
    {
        // Cr�er un menu contextuel
        juce::PopupMenu menu;

        // Ajouter deux options
        menu.addItem(1, "Inputs");
        menu.addItem(2, "Outputs");

        // Afficher le menu � la position du clic
        // event.position est relatif au composant, on convertit en coordonn�es globales
        auto screenPos = getScreenPosition() + event.position.toInt();

        // Montrer le menu et r�cup�rer l'ID de l'option s�lectionn�e
        menu.showMenuAsync(juce::PopupMenu::Options().withTargetScreenArea({ screenPos.x, screenPos.y, 1, 1 }),
            [this](int result)
            {
                if (result == 1)
                {
                    // Afficher une bo�te de dialogue avec un menu d�roulant
                    juce::AlertWindow dialog("Choisir une valeur",
                        "S�lectionnez une valeur de 1 � 10 :",
                        juce::AlertWindow::QuestionIcon);

                    // Cr�er les options du menu d�roulant (1 � 10)
                    juce::StringArray choices;
                    for (int i = 1; i <= 10; ++i)
                        choices.add(juce::String(i));

                    // Ajouter un menu d�roulant
                    dialog.addComboBox("valueSelector", choices, "Valeur");

                    // Ajouter des boutons
                    dialog.addButton("OK", 1, juce::KeyPress(juce::KeyPress::returnKey));
                    dialog.addButton("Annuler", 0, juce::KeyPress(juce::KeyPress::escapeKey));

                    // Afficher la bo�te de dialogue et g�rer le r�sultat
                    if (1 == 1)
                    {
                        // R�cup�rer la valeur s�lectionn�e (index commence � 1)
                        int selectedValue = dialog.getComboBoxComponent("valueSelector")->getSelectedItemIndex() + 1;
                        juce::Logger::writeToLog("Valeur s�lectionn�e : " + juce::String(selectedValue));
                        // Exemple : utiliser la valeur dans le processeur
                        // processor.setParameterValue(selectedValue);
                    }
                    else
                    {
                        juce::Logger::writeToLog("Dialogue annul�");
                    }
                }
                else if (result == 2)
                {
                    // Action pour Option 2
                    juce::Logger::writeToLog("Option 2 s�lectionn�e");
                }
        
            });
    }
}



void ComponentPerso :: setSelected(bool selected)
{
    isSelected = selected;
    repaint(); // Redessiner pour mettre � jour la bordure
}

bool ComponentPerso :: isComponentSelected() const { return isSelected; }



