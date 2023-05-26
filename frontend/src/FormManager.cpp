#include <LibPaths.h>
#include <FormManager.h>

FormManager::FormManager(Rml::Context* context)
{
    this->context = context;
};

// Загрузить страницу
Rml::ElementDocument* FormManager::AddForm(const fs::path path)  
{
    Rml::ElementDocument* form = this->context->LoadDocument(path.string());
    this->forms[path] = form;
    if (form) {
        form->Hide();
    }
    return form;
}

Rml::ElementDocument* FormManager::GetForm(const fs::path path) 
{
    return this->forms[path];
}

// Отобразить страницу
void FormManager::ShowForm(const fs::path path) 
{
    auto it = this->forms.find(path);
    if (it != this->forms.end()) {
        it->second->Show();
    }
}

// Скрыть страницу
void FormManager::HideForm(const fs::path path) 
{
    auto it = this->forms.find(path);
    if (it != this->forms.end()) {
        it->second->Hide();
    }
}

// Закрыть страницу
void FormManager::CloseForm(const fs::path path) 
{
    auto it = this->forms.find(path);
    if (it != this->forms.end()) {
        it->second->Close();
        this->forms.erase(it);
    }
}