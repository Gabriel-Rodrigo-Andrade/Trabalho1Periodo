#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name, adress;
    string login;
    string login_gabriel = "gabrielandrade";
    int passaword_gabriel = 2024122599;
    const double salario_estagiario = 800;
    const double desc_previdenciario = 0.08;
    const double imposto_de_renda = 0.12;
    int operacao_login, operacao_funcionario, passaword, CPF, admiss_date, dias_trabalhados;
    double hora_extra, calc_hora_extra, base_salarial, salario_final_sh, salario_final_ch, valor_inss, valor_irff, total_desc, salario_final_temp, salario_mes_temp;

    cout << "=============FACA LOGIN OU REGISTRE-SE============" << endl;
    cout << "1. Efetuar Login.   " << "2. Registre-se ja." << "\nEscolha uma das opcoes." << endl;
    cin >> operacao_login;
    switch (operacao_login)
    {
    case 1:
        cout << "==============FACA SEU LOGIN================" << endl;
        cout << "Login: ";
        cin >> login;
        cout << "Senha: ";
        cin >> passaword;
        if (login != login_gabriel || passaword != passaword_gabriel)
        {
            cout << "Erro! Login ou Senha incorreto(s)";
        }
        else
        {
            string name_padrao = "Gabriel";
            string cpf_padrao = "133.717.079-89";
            string endereco_padrao = "Rua Santo Alberti, 154";
            cout << "\n=> Login efetuado com sucesso! <=" << endl;
            cout << "Agora escolha uma das opcoes abaixo que correspondem com sua contratacao." << endl;
            cout << "1. Efetivo" << endl
                 << "2. Temporario" << endl
                 << "3. Estagiario" << endl;
            cin >> operacao_funcionario;

            switch (operacao_funcionario)
            {
            case 1:
                cout << "\nEscreva qual e a sua base salarial: ";
                cin >> base_salarial;
                cout << "\nAgora escreva a quantidade de horas extra que possui (caso nao tenha digite 0): ";
                cin >> hora_extra;

                calc_hora_extra = ((base_salarial / 200) * 1.5 * hora_extra);
                valor_inss = (base_salarial + calc_hora_extra) * desc_previdenciario;
                valor_irff = (base_salarial + calc_hora_extra) * imposto_de_renda;
                total_desc = valor_inss + valor_irff;
                salario_final_sh = base_salarial - total_desc;
                salario_final_ch = (base_salarial + calc_hora_extra) - total_desc;

                if (hora_extra < 1)
                {
                    cout << "\n __________________________________________________________________ " << endl
                         << "| Nome: " << name_padrao << "                  Recibo de Pagamento de Salario" << endl
                         << "| Endereco: " << endereco_padrao << endl
                         << "| CPF: " << cpf_padrao << endl
                         << "|__________________________________________________________________ " << endl;
                    cout << "|      Descricao           Referencias     Proventos     Descontos |" << endl
                         << "|__________________________________________________________________|" << endl;
                    cout << "| SALARIO BASE            | " << "     " << "          " << base_salarial << "     " << "     " << endl;
                    cout << "| INSS                    | " << "8%   " << "          " << "     " << "         " << valor_inss << endl;
                    cout << "| IRRF                    | " << "12%  " << "          " << "     " << "         " << valor_irff << endl
                         << "|                         |" << endl
                         << "|                         |" << endl
                         << "|_________________________|_________________________________________ " << endl;
                    cout << "|                       Total dos Vencimentos   |   Total Descontos |" << endl;
                    cout << "|                       " << base_salarial << "                         " << total_desc << endl
                         << "|__________________________________________________________________ " << endl;
                    cout << "|                       Liquido a Receber =        RS" << salario_final_sh << endl
                         << "|__________________________________________________________________ ";
                }
                else if (hora_extra > 1)
                {
                    cout << "\n __________________________________________________________________ " << endl
                         << "| Nome: " << name_padrao << "                  Recibo de Pagamento de Salario" << endl
                         << "| Endereco: " << endereco_padrao << endl
                         << "| CPF: " << cpf_padrao << endl
                         << "|__________________________________________________________________ " << endl;
                    cout << "|      Descricao           Referencias     Proventos     Descontos |" << endl
                         << "|__________________________________________________________________|" << endl;
                    cout << "| SALARIO BASE            | " << "      " << "         " << base_salarial << "     " << "     " << endl;
                    cout << "| HORAS EXTRAS            | " << "1.5%/h" << "         " << calc_hora_extra << endl;
                    cout << "| INSS                    | " << "8%    " << "         " << "     " << "     " << valor_inss << endl;
                    cout << "| IRRF                    | " << "12%   " << "         " << "     " << "     " << valor_irff << endl
                         << "|                         |" << endl
                         << "|                         |" << endl
                         << "|_________________________|_________________________________________ " << endl;
                    cout << "|                       Total dos Vencimentos   |   Total Descontos |" << endl;
                    cout << "|                       " << (base_salarial + calc_hora_extra) << "                         " << total_desc << endl
                         << "|__________________________________________________________________ " << endl;
                    cout << "|                       Liquido a Receber =        RS" << salario_final_ch << endl
                         << "|__________________________________________________________________ ";
                }
                else
                {
                    cout << "\nValores invalidos, reinicie o sistema e tente novamente.";
                }

                break;

            case 2:
                cout << "\nEscreva sua base salarial diaria: ";
                cin >> base_salarial;
                cout << "\nAgora informe quantos dias voce trabalhou: ";
                cin >> dias_trabalhados;

                if (dias_trabalhados >= 1 && base_salarial >= 1)
                {
                    salario_mes_temp = base_salarial * dias_trabalhados;
                    valor_inss = salario_mes_temp * desc_previdenciario;
                    valor_irff = salario_mes_temp * imposto_de_renda;
                    total_desc = valor_inss + valor_irff;
                    salario_final_temp = salario_mes_temp - total_desc;

                    cout << "\n __________________________________________________________________ " << endl
                         << "| Nome: " << name_padrao << "                  Recibo de Pagamento de Salario" << endl
                         << "| Endereco: " << endereco_padrao << endl
                         << "| CPF: " << cpf_padrao << endl
                         << "|__________________________________________________________________ " << endl;
                    cout << "|      Descricao           Referencias     Proventos     Descontos |" << endl
                         << "|__________________________________________________________________|" << endl;
                    cout << "| SALARIO BASE            | " << dias_trabalhados << " Dias" << "         " << salario_mes_temp << "     " << "     " << endl;
                    cout << "| INSS                    | " << "8%    " << "         " << "     " << "          " << valor_inss << endl;
                    cout << "| IRRF                    | " << "12%   " << "         " << "     " << "          " << valor_irff << endl
                         << "|                         |" << endl
                         << "|                         |" << endl
                         << "|_________________________|_________________________________________ " << endl;
                    cout << "|                       Total dos Vencimentos   |   Total Descontos |" << endl;
                    cout << "|                       " << salario_mes_temp << "                         " << total_desc << endl
                         << "|__________________________________________________________________ " << endl;
                    cout << "|                       Liquido a Receber =        RS" << salario_final_temp << endl
                         << "|__________________________________________________________________ ";
                }
                else
                {
                    cout << "\nValores invalidos, reinicie o sistema e tente novamente.";
                }
                break;

            case 3:
                cout << "\n __________________________________________________________________ " << endl
                     << "| Nome: " << name_padrao << "                  Recibo de Pagamento de Salario" << endl
                     << "| Endereco: " << endereco_padrao << endl
                     << "| CPF: " << cpf_padrao << endl
                     << "|__________________________________________________________________ " << endl;
                cout << "|      Descricao           Referencias     Proventos     Descontos |" << endl
                     << "|__________________________________________________________________|" << endl;
                cout << "| SALARIO BASE            | " << "     " << "          " << salario_estagiario << "     " << "     " << endl
                     << "|                         |" << endl
                     << "|                         |" << endl
                     << "|                         |" << endl;
                cout << "|                       Total dos Vencimentos   |   Total Descontos |" << endl;
                cout << "|                       " << salario_estagiario << endl
                     << "|__________________________________________________________________ " << endl;
                cout << "|                       Liquido a Receber =        RS" << salario_estagiario << endl
                     << "|__________________________________________________________________ ";

                break;

            default:
                break;
            }
        }
        break;
    case 2:
        cout << "========PREENCHA O CADASTRO PARA SE REGISTRAR========" << endl;
        cout << "Nome: ";
        cin >> name;
        cout << "\nEndereco: ";
        cin >> adress;
        cout << "\nDigite seu CPF: ";
        cin >> CPF;
        cout << "Sua data de Admissao: ";
        cin >> admiss_date;
        cout << "\nAgora escolha uma das opcoes abaixo que correspondem com sua contratacao." << endl;
        cout << "1. Efetivo" << endl
             << "2. Temporario" << endl
             << "3. Estagiario" << endl;
        cin >> operacao_funcionario;
        switch (operacao_funcionario)
        {
        case 1:
            cout << "\nEscreva qual e a sua base salarial: ";
            cin >> base_salarial;
            cout << "\nAgora escreva a quantidade de horas extra que possui (caso nao tenha digite 0): ";
            cin >> hora_extra;

            calc_hora_extra = ((base_salarial / 200) * 1.5 * hora_extra);
            valor_inss = (base_salarial + calc_hora_extra) * desc_previdenciario;
            valor_irff = (base_salarial + calc_hora_extra) * imposto_de_renda;
            total_desc = valor_inss + valor_irff;
            salario_final_sh = base_salarial - total_desc;
            salario_final_ch = (base_salarial + calc_hora_extra) - total_desc;

            if (hora_extra < 1)
            {
                cout << "\n __________________________________________________________________ " << endl
                     << "| Nome: " << name << "                  Recibo de Pagamento de Salario" << endl
                     << "| Endereco: " << adress << endl
                     << "| CPF: " << CPF << endl
                     << "| Data Admissao: " << admiss_date << endl
                     << "|__________________________________________________________________ " << endl;
                cout << "|      Descricao           Referencias     Proventos     Descontos |" << endl
                     << "|__________________________________________________________________|" << endl;
                cout << "| SALARIO BASE            | " << "     " << "          " << base_salarial << "     " << "     " << endl;
                cout << "| INSS                    | " << "8%   " << "          " << "     " << "         " << valor_inss << endl;
                cout << "| IRRF                    | " << "12%  " << "          " << "     " << "         " << valor_irff << endl
                     << "|                         |" << endl
                     << "|                         |" << endl
                     << "|_________________________|_________________________________________ " << endl;
                cout << "|                       Total dos Vencimentos   |   Total Descontos |" << endl;
                cout << "|                       " << base_salarial << "                         " << total_desc << endl
                     << "|__________________________________________________________________ " << endl;
                cout << "|                       Liquido a Receber =        RS" << salario_final_sh << endl
                     << "|__________________________________________________________________ ";
            }
            else if (hora_extra > 1)
            {
                cout << "\n __________________________________________________________________ " << endl
                     << "| Nome: " << name << "                  Recibo de Pagamento de Salario" << endl
                     << "| Endereco: " << adress << endl
                     << "| CPF: " << CPF << endl
                     << "| Data Admissao: " << admiss_date << endl
                     << "|__________________________________________________________________ " << endl;
                cout << "|      Descricao           Referencias     Proventos     Descontos |" << endl
                     << "|__________________________________________________________________|" << endl;
                cout << "| SALARIO BASE            | " << "      " << "         " << base_salarial << "     " << "     " << endl;
                cout << "| HORAS EXTRAS            | " << "1.5%/h" << "         " << calc_hora_extra << endl;
                cout << "| INSS                    | " << "8%    " << "         " << "     " << "     " << valor_inss << endl;
                cout << "| IRRF                    | " << "12%   " << "         " << "     " << "     " << valor_irff << endl
                     << "|                         |" << endl
                     << "|                         |" << endl
                     << "|_________________________|_________________________________________ " << endl;
                cout << "|                       Total dos Vencimentos   |   Total Descontos |" << endl;
                cout << "|                       " << (base_salarial + calc_hora_extra) << "                         " << total_desc << endl
                     << "|__________________________________________________________________ " << endl;
                cout << "|                       Liquido a Receber =        RS" << salario_final_ch << endl
                     << "|__________________________________________________________________ ";
            }
            else
            {
                cout << "\nValores invalidos, reinicie o sistema e tente novamente.";
            }
            break;

        case 2:
            cout << "\nEscreva sua base salarial diaria: ";
            cin >> base_salarial;
            cout << "\nAgora informe quantos dias voce trabalhou: ";
            cin >> dias_trabalhados;
            if (dias_trabalhados >= 1 && base_salarial >= 1)
            {
                salario_mes_temp = base_salarial * dias_trabalhados;
                valor_inss = salario_mes_temp * desc_previdenciario;
                valor_irff = salario_mes_temp * imposto_de_renda;
                total_desc = valor_inss + valor_irff;
                salario_final_temp = salario_mes_temp - total_desc;

                cout << "\n __________________________________________________________________ " << endl
                     << "| Nome: " << name << "                  Recibo de Pagamento de Salario" << endl
                     << "| Endereco: " << adress << endl
                     << "| CPF: " << CPF << endl
                     << "| Data Admissao: " << admiss_date << endl
                     << "|__________________________________________________________________ " << endl;
                cout << "|      Descricao           Referencias     Proventos     Descontos |" << endl
                     << "|__________________________________________________________________|" << endl;
                cout << "| SALARIO BASE            | " << dias_trabalhados << " Dias" << "         " << salario_mes_temp << "     " << "     " << endl;
                cout << "| INSS                    | " << "8%    " << "         " << "     " << "          " << valor_inss << endl;
                cout << "| IRRF                    | " << "12%   " << "         " << "     " << "          " << valor_irff << endl
                     << "|                         |" << endl
                     << "|                         |" << endl
                     << "|_________________________|_________________________________________ " << endl;
                cout << "|                       Total dos Vencimentos   |   Total Descontos |" << endl;
                cout << "|                       " << salario_mes_temp << "                         " << total_desc << endl
                     << "|__________________________________________________________________ " << endl;
                cout << "|                       Liquido a Receber =        RS" << salario_final_temp << endl
                     << "|__________________________________________________________________ ";
            }
            else
            {
                cout << "Valores invalidos, reinicie o sistema e tente novamente.";
            }
            break;

        case 3:
            cout << "\n __________________________________________________________________ " << endl
                 << "| Nome: " << name << "                  Recibo de Pagamento de Salario" << endl
                 << "| Endereco: " << adress << endl
                 << "| CPF: " << CPF << endl
                 << "| Data Admissao: " << admiss_date << endl
                 << "|__________________________________________________________________ " << endl;
            cout << "|      Descricao           Referencias     Proventos     Descontos |" << endl
                 << "|__________________________________________________________________|" << endl;
            cout << "| SALARIO BASE            | " << "     " << "          " << salario_estagiario << "     " << "     " << endl
                 << "|                         |" << endl
                 << "|                         |" << endl
                 << "|                         |" << endl;
            cout << "|                       Total dos Vencimentos   |   Total Descontos |" << endl;
            cout << "|                       " << salario_estagiario << endl
                 << "|__________________________________________________________________ " << endl;
            cout << "|                       Liquido a Receber =        RS" << salario_estagiario << endl
                 << "|__________________________________________________________________ ";
            break;

        default:
            break;
        }
    default:
        cout << "\nVoce saiu da tela do sistema de escolha, reinicie e tente novamente.";
        break;
    }

    return 0;
}