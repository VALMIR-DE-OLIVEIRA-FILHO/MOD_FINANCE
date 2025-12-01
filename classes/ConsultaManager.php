<?php

class ConsultaManager
{
    private $arquivoConsultas;
    private $arquivoFuncionarios;

    public function __construct($arquivoConsultas, $arquivoFuncionarios)
    {
        $this->arquivoConsultas = $arquivoConsultas;
        $this->arquivoFuncionarios = $arquivoFuncionarios;

        if (!file_exists($this->arquivoConsultas)) {
            file_put_contents($this->arquivoConsultas, "");
        }
    }

    // Busca o ID do colaborador pelo nome
    public function getIdColaborador($nome)
    {
        if (!file_exists($this->arquivoFuncionarios)) return "desconhecido";

        $linhas = file($this->arquivoFuncionarios, FILE_IGNORE_NEW_LINES);

        foreach ($linhas as $linha) {
            $dados = explode(";", $linha);

            if (strtolower(trim($dados[0])) === strtolower(trim($nome))) {
                return $dados[2]; // ID do colaborador
            }
        }

        return "desconhecido";
    }

    // Registra a consulta
    public function registrarConsulta($nomeUsuario, $inicio, $fim, $tipo)
    {
        $idConsulta = uniqid("C");
        $idColaborador = $this->getIdColaborador($nomeUsuario);
        $dataConsulta = date("Y-m-d H:i:s");

        $registro = 
            $idConsulta . "|" .
            $idColaborador . "|" .
            $inicio . "|" .
            $fim . "|" .
            $tipo . "|" .
            $dataConsulta . PHP_EOL;

        file_put_contents($this->arquivoConsultas, $registro, FILE_APPEND);
    }
}
