#include "PhysicalVariable.h"

PhysicalVariable::PhysicalVariable(Type type, size_t size)
{
    if (type.is_array)
    {
        // value_ is default-constructed as the first alternative (FieldsMap),
        // so we must switch it to Array before using std::get<Array>.
        // Каждая ячейка должна содержать реальный объект (а не нулевой
        // shared_ptr), иначе запись `arr[i] = ...` (через `*cell = *value`)
        // разыменует nullptr. Тип элемента — базовый тип массива.
        Type element_type = type;
        element_type.is_array = false;
        Array cells;
        cells.reserve(size);
        for (size_t i = 0; i < size; ++i)
        {
            cells.push_back(std::make_shared<PhysicalVariable>(element_type));
        }
        value_ = std::move(cells);
    }
    else
    {
        if (size != 1)
            throw std::runtime_error(
                "Don't use PhysicalVariable() like this.");
        if (type == Type("int"))
        {
            SetValue(0);
        }
        else if (type == Type("bool"))
        {
            SetValue(false);
        }
        else
        {
            // A user-defined class instance: store its fields in a map.
            value_ = FieldsMap{};
        }
    }
}

PhysicalVariable::PhysicalVariable(int init_val) { SetValue(init_val); }

PhysicalVariable::PhysicalVariable(bool init_val) { SetValue(init_val); }

int PhysicalVariable::GetInt() const { return std::get<int>(value_); }

void PhysicalVariable::SetValue(int new_val) { value_ = new_val; }

bool PhysicalVariable::GetBool() const { return std::get<bool>(value_); }

void PhysicalVariable::SetValue(bool new_val) { value_ = new_val; }

PhysicalVariable::variant_type PhysicalVariable::GetValue() const
{
    return value_;
}

PhysicalVariable::PtrType PhysicalVariable::GetOnIndex(size_t i)
{
    return std::get<Array>(value_)[i];
}

void PhysicalVariable::SetOnIndex(size_t i, PhysicalVariable::PtrType new_val)
{
    std::get<Array>(value_)[i] = std::move(new_val);
}

void PhysicalVariable::SetField(const std::string &field_name,
                                PhysicalVariable::PtrType new_val)
{
    std::get<FieldsMap>(value_)[field_name] = std::move(new_val);
}

PhysicalVariable::PtrType
PhysicalVariable::GetField(const std::string &field_name) const
{
    return std::get<FieldsMap>(value_).at(field_name);
}

int PhysicalVariable::GetLength() const
{
    return std::get<Array>(value_).size();
}

PhysicalVariable::PhysicalVariable() = default;
